#include "Int64Util.h"
#include <stdio.h>
#include <utility>

using namespace std;

typedef unsigned char uint8;
typedef unsigned int uint32;
typedef unsigned long long uint64;
typedef pair<uint64, uint64> uint128;

#define uint32_in_expected_order(x) (x)
#define uint64_in_expected_order(x) (x)

#define bswap_32(x) _byteswap_ulong(x)
#define bswap_64(x) _byteswap_uint64(x)

#define PERMUTE3(a, b, c) do { std::swap(a, b); std::swap(a, c); } while (0)

// Some primes between 2^63 and 2^64 for various uses.
const uint64 k0 = 0xc3a5c85c97cb3127ULL;
const uint64 k1 = 0xb492b66fbe98f273ULL;
const uint64 k2 = 0x9ae16a3b2f90404fULL;

// Magic numbers for 32-bit hashing.  Copied from Murmur3.
const uint32 c1 = 0xcc9e2d51;
const uint32 c2 = 0x1b873593;

struct GObjectID_private
{
	static uint32 fmix(uint32 h)
	{
		h ^= h >> 16;
		h *= 0x85ebca6b;
		h ^= h >> 13;
		h *= 0xc2b2ae35;
		h ^= h >> 16;
		return h;
	}

	static uint32 Rotate32(uint32 val, int shift) {
		// Avoid shifting by 32: doing so yields an undefined result.
		return shift == 0 ? val : ((val >> shift) | (val << (32 - shift)));
	}

	static uint32 Mur(uint32 a, uint32 h) {
		// Helper from Murmur3 for combining two 32-bit values.
		a *= c1;
		a = Rotate32(a, 17);
		a *= c2;
		h ^= a;
		h = Rotate32(h, 19);
		return h * 5 + 0xe6546b64;
	}

	static inline uint64 Uint128Low64(const uint128& x) { return x.first; }
	static inline uint64 Uint128High64(const uint128& x) { return x.second; }

	static uint32 UNALIGNED_LOAD32(const char *p) {
		uint32 result;
		memcpy(&result, p, sizeof(result));
		return result;
	}

	static uint64 UNALIGNED_LOAD64(const char *p) {
		uint64 result;
		memcpy(&result, p, sizeof(result));
		return result;
	}

	static uint32 Fetch32(const char *p) {
		return uint32_in_expected_order(UNALIGNED_LOAD32(p));
	}

	static uint64 Fetch64(const char *p) {
		return uint64_in_expected_order(UNALIGNED_LOAD64(p));
	}

	static uint64 Rotate(uint64 val, int shift) {
		// Avoid shifting by 64: doing so yields an undefined result.
		return shift == 0 ? val : ((val >> shift) | (val << (64 - shift)));
	}

	static uint64 ShiftMix(uint64 val) {
		return val ^ (val >> 47);
	}

	static uint64 HashLen16(uint64 u, uint64 v) {
		return Hash128to64(uint128(u, v));
	}

	static uint64 HashLen16(uint64 u, uint64 v, uint64 mul) {
		// Murmur-inspired hashing.
		uint64 a = (u ^ v) * mul;
		a ^= (a >> 47);
		uint64 b = (v ^ a) * mul;
		b ^= (b >> 47);
		b *= mul;
		return b;
	}

	static uint64 HashLen0to16(const char *s, size_t len) {
		if (len >= 8) {
			uint64 mul = k2 + len * 2;
			uint64 a = Fetch64(s) + k2;
			uint64 b = Fetch64(s + len - 8);
			uint64 c = Rotate(b, 37) * mul + a;
			uint64 d = (Rotate(a, 25) + b) * mul;
			return HashLen16(c, d, mul);
		}
		if (len >= 4) {
			uint64 mul = k2 + len * 2;
			uint64 a = Fetch32(s);
			return HashLen16(len + (a << 3), Fetch32(s + len - 4), mul);
		}
		if (len > 0) {
			uint8 a = s[0];
			uint8 b = s[len >> 1];
			uint8 c = s[len - 1];
			uint32 y = static_cast<uint32>(a) + (static_cast<uint32>(b) << 8);
			uint32 z = len + (static_cast<uint32>(c) << 2);
			return ShiftMix(y * k2 ^ z * k0) * k2;
		}
		return k2;
	}

	static uint64 HashLen17to32(const char *s, size_t len) {
		uint64 mul = k2 + len * 2;
		uint64 a = Fetch64(s) * k1;
		uint64 b = Fetch64(s + 8);
		uint64 c = Fetch64(s + len - 8) * mul;
		uint64 d = Fetch64(s + len - 16) * k2;
		return HashLen16(Rotate(a + b, 43) + Rotate(c, 30) + d,
			a + Rotate(b + k2, 18) + c, mul);
	}

	static uint64 HashLen33to64(const char *s, size_t len) {
		uint64 mul = k2 + len * 2;
		uint64 a = Fetch64(s) * k2;
		uint64 b = Fetch64(s + 8);
		uint64 c = Fetch64(s + len - 24);
		uint64 d = Fetch64(s + len - 32);
		uint64 e = Fetch64(s + 16) * k2;
		uint64 f = Fetch64(s + 24) * 9;
		uint64 g = Fetch64(s + len - 8);
		uint64 h = Fetch64(s + len - 16) * mul;
		uint64 u = Rotate(a + g, 43) + (Rotate(b, 30) + c) * 9;
		uint64 v = ((a + g) ^ d) + f + 1;
		uint64 w = bswap_64((u + v) * mul) + h;
		uint64 x = Rotate(e + f, 42) + c;
		uint64 y = (bswap_64((v + w) * mul) + g) * mul;
		uint64 z = e + f + c;
		a = bswap_64((x + z) * mul + y) + b;
		b = ShiftMix((z + a) * mul + d + h) * mul;
		return b + x;
	}

	static inline uint64 Hash128to64(const uint128& x) {
		// Murmur-inspired hashing.
		const uint64 kMul = 0x9ddfea08eb382d69ULL;
		uint64 a = (Uint128Low64(x) ^ Uint128High64(x)) * kMul;
		a ^= (a >> 47);
		uint64 b = (Uint128High64(x) ^ a) * kMul;
		b ^= (b >> 47);
		b *= kMul;
		return b;
	}

	static pair<uint64, uint64> WeakHashLen32WithSeeds(
		uint64 w, uint64 x, uint64 y, uint64 z, uint64 a, uint64 b) {
			a += w;
			b = Rotate(b + a + z, 21);
			uint64 c = a;
			a += x;
			a += y;
			b += Rotate(a, 44);
			return make_pair(a + z, b + c);
	}

	static pair<uint64, uint64> WeakHashLen32WithSeeds(
		const char* s, uint64 a, uint64 b) {
			return WeakHashLen32WithSeeds(Fetch64(s),
				Fetch64(s + 8),
				Fetch64(s + 16),
				Fetch64(s + 24),
				a,
				b);
	}

	static uint32 Hash32Len13to24(const char *s, size_t len) {
		uint32 a = Fetch32(s - 4 + (len >> 1));
		uint32 b = Fetch32(s + 4);
		uint32 c = Fetch32(s + len - 8);
		uint32 d = Fetch32(s + (len >> 1));
		uint32 e = Fetch32(s);
		uint32 f = Fetch32(s + len - 4);
		uint32 h = len;

		return fmix(Mur(f, Mur(e, Mur(d, Mur(c, Mur(b, Mur(a, h)))))));
	}

	static uint32 Hash32Len0to4(const char *s, size_t len) {
		uint32 b = 0;
		uint32 c = 9;
		for (size_t i = 0; i < len; i++) {
			signed char v = s[i];
			b = b * c1 + v;
			c ^= b;
		}
		return fmix(Mur(b, Mur(len, c)));
	}


	static uint32 Hash32Len5to12(const char *s, size_t len) {
		uint32 a = len, b = len * 5, c = 9, d = b;
		a += Fetch32(s);
		b += Fetch32(s + len - 4);
		c += Fetch32(s + ((len >> 1) & 4));
		return fmix(Mur(c, Mur(b, Mur(a, d))));
	}

	static uint32 CityHash32(const char *s, size_t len) {
		if (len <= 24) {
			return len <= 12 ?
				(len <= 4 ? Hash32Len0to4(s, len) : Hash32Len5to12(s, len)) :
				Hash32Len13to24(s, len);
		}

		// len > 24
		uint32 h = len, g = c1 * len, f = g;
		uint32 a0 = Rotate32(Fetch32(s + len - 4) * c1, 17) * c2;
		uint32 a1 = Rotate32(Fetch32(s + len - 8) * c1, 17) * c2;
		uint32 a2 = Rotate32(Fetch32(s + len - 16) * c1, 17) * c2;
		uint32 a3 = Rotate32(Fetch32(s + len - 12) * c1, 17) * c2;
		uint32 a4 = Rotate32(Fetch32(s + len - 20) * c1, 17) * c2;
		h ^= a0;
		h = Rotate32(h, 19);
		h = h * 5 + 0xe6546b64;
		h ^= a2;
		h = Rotate32(h, 19);
		h = h * 5 + 0xe6546b64;
		g ^= a1;
		g = Rotate32(g, 19);
		g = g * 5 + 0xe6546b64;
		g ^= a3;
		g = Rotate32(g, 19);
		g = g * 5 + 0xe6546b64;
		f += a4;
		f = Rotate32(f, 19);
		f = f * 5 + 0xe6546b64;
		size_t iters = (len - 1) / 20;
		do {
			uint32 a0 = Rotate32(Fetch32(s) * c1, 17) * c2;
			uint32 a1 = Fetch32(s + 4);
			uint32 a2 = Rotate32(Fetch32(s + 8) * c1, 17) * c2;
			uint32 a3 = Rotate32(Fetch32(s + 12) * c1, 17) * c2;
			uint32 a4 = Fetch32(s + 16);
			h ^= a0;
			h = Rotate32(h, 18);
			h = h * 5 + 0xe6546b64;
			f += a1;
			f = Rotate32(f, 19);
			f = f * c1;
			g += a2;
			g = Rotate32(g, 18);
			g = g * 5 + 0xe6546b64;
			h ^= a3 + a1;
			h = Rotate32(h, 19);
			h = h * 5 + 0xe6546b64;
			g ^= a4;
			g = bswap_32(g) * 5;
			h += a4 * 5;
			h = bswap_32(h);
			f += a0;
			PERMUTE3(f, h, g);
			s += 20;
		} while (--iters != 0);
		g = Rotate32(g, 11) * c1;
		g = Rotate32(g, 17) * c1;
		f = Rotate32(f, 11) * c1;
		f = Rotate32(f, 17) * c1;
		h = Rotate32(h + g, 19);
		h = h * 5 + 0xe6546b64;
		h = Rotate32(h, 17) * c1;
		h = Rotate32(h + f, 19);
		h = h * 5 + 0xe6546b64;
		h = Rotate32(h, 17) * c1;
		return h;
	}

	static uint64 CityHash64(const char *s, size_t len) {
		if (len <= 32) {
			if (len <= 16) {
				return HashLen0to16(s, len);
			} else {
				return HashLen17to32(s, len);
			}
		} else if (len <= 64) {
			return HashLen33to64(s, len);
		}

		// For strings over 64 bytes we hash the end first, and then as we
		// loop we keep 56 bytes of state: v, w, x, y, and z.
		uint64 x = Fetch64(s + len - 40);
		uint64 y = Fetch64(s + len - 16) + Fetch64(s + len - 56);
		uint64 z = HashLen16(Fetch64(s + len - 48) + len, Fetch64(s + len - 24));
		pair<uint64, uint64> v = WeakHashLen32WithSeeds(s + len - 64, len, z);
		pair<uint64, uint64> w = WeakHashLen32WithSeeds(s + len - 32, y + k1, x);
		x = x * k1 + Fetch64(s);

		// Decrease len to the nearest multiple of 64, and operate on 64-byte chunks.
		len = (len - 1) & ~static_cast<size_t>(63);
		do {
			x = Rotate(x + y + v.first + Fetch64(s + 8), 37) * k1;
			y = Rotate(y + v.second + Fetch64(s + 48), 42) * k1;
			x ^= w.second;
			y += v.first + Fetch64(s + 40);
			z = Rotate(z + w.first, 33) * k1;
			v = WeakHashLen32WithSeeds(s, v.second * k1, x + w.first);
			w = WeakHashLen32WithSeeds(s + 32, z + w.second, y + Fetch64(s + 16));
			std::swap(z, x);
			s += 64;
			len -= 64;
		} while (len != 0);
		return HashLen16(HashLen16(v.first, w.first) + ShiftMix(y) * k1 + z,
			HashLen16(v.second, w.second) + x);
	}

};

unsigned __int64 Int64Util::NewID()
{
	GUID guid;
	::CoCreateGuid(&guid);
	char szGuid[64];
	sprintf_s(szGuid,"%08X%04X%04X%02X%02X%02X%02X%02X%02X%02X%02X",
		guid.Data1, guid.Data2, guid.Data3,
		guid.Data4[0], guid.Data4[1], guid.Data4[2],
		guid.Data4[3], guid.Data4[4], guid.Data4[5],
		guid.Data4[6], guid.Data4[7]);
	return GObjectID_private::CityHash64(szGuid, 32);
}

unsigned __int64 Int64Util::NewID(std::string & seed)
{
	return GObjectID_private::CityHash64(seed.c_str(), seed.size());
}

unsigned int Int64Util::NewID32()
{
	GUID guid;
	::CoCreateGuid(&guid);
	char szGuid[64];
	sprintf_s(szGuid,"%08X%04X%04X%02X%02X%02X%02X%02X%02X%02X%02X",
		guid.Data1, guid.Data2, guid.Data3,
		guid.Data4[0], guid.Data4[1], guid.Data4[2],
		guid.Data4[3], guid.Data4[4], guid.Data4[5],
		guid.Data4[6], guid.Data4[7]);

	return GObjectID_private::CityHash32(szGuid, 32);
}

void Int64Util::InitSeed()
{
	//never to use
}

std::wstring Helper::GetExecutePath()
{
	wchar_t filename[MAX_PATH];
	DWORD result = GetModuleFileName(NULL, filename, MAX_PATH); if (result == FALSE){ _ASSERT(false); return false; return L""; }
	wchar_t * end = wcsrchr(filename, L'\\');
	*(end + 1) = '\0';
	return filename;
}

void * Helper::CreateWin32TempFile(std::wstring & out_filename)
{
	wchar_t tmpFilename[MAX_PATH];
	DWORD result = GetTempPath(MAX_PATH, tmpFilename); if (result == 0) { _ASSERT (false); return NULL; }
	result = GetTempFileName(tmpFilename, NULL, NULL, tmpFilename); if (result == 0) { _ASSERT (false); return NULL; }
	out_filename = tmpFilename;
	HANDLE hFile = CreateFile(tmpFilename, GENERIC_READ|GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); if (INVALID_HANDLE_VALUE == hFile) { _ASSERT(false); DeleteFile(tmpFilename); return NULL; }
	return hFile;
}

std::wstring Helper::GetTempFilename()
{
	wchar_t tmpFilename[MAX_PATH];
	DWORD result = GetTempPath(MAX_PATH, tmpFilename); if (result == 0) { _ASSERT(false); return false; return L""; }
	size_t len = wcslen(tmpFilename); _ASSERT(len > 0);
	if (tmpFilename[len-1] == L'\\' || tmpFilename[len-1] == L'/'){ tmpFilename[len-1] = '\0'; }
	swprintf_s(tmpFilename, MAX_PATH, L"%s\\%I64u", tmpFilename, Int64Util::NewID());
	return tmpFilename;
}

static std::wstring GetTempName()
{
	wchar_t tempDirName[64];
	errno_t err = _ui64tow_s(Int64Util::NewID(), tempDirName, 64, 10); _ASSERT(err == 0);
	return tempDirName;
}

std::wstring Helper::GetUserTempDirectory()
{
	wchar_t tmpFilename[MAX_PATH];
	DWORD result = GetTempPath(MAX_PATH, tmpFilename); if (result == 0) { _ASSERT(false); return false; return L""; }
	return std::wstring(tmpFilename);
}

std::wstring Helper::GetTempDirectory()
{
	wchar_t tempDirName[64];
	errno_t err = _ui64tow_s(Int64Util::NewID(), tempDirName, 64, 10); _ASSERT(err == 0);
	std::wstring result = ComboPath(GetUserTempDirectory().c_str(), tempDirName);
	BOOL retVal = CreateDirectory(result.c_str(), NULL); _ASSERT(retVal);
	return retVal ?  result : L"";
}

bool Helper::StrEndWith(const wchar_t * str, const wchar_t * token)
{
	size_t lenStr = wcslen(str);
	size_t lenToken = wcslen(token);
	if (lenStr < lenToken){ return false; }
	size_t endStart = lenStr - lenToken;
	for(size_t i=0; i<lenToken; ++i){
		if (str[endStart + i] != token[i]){ return false; }
	}
	return true;
}

bool Helper::StrStartWith(const wchar_t * str, const wchar_t * token)
{
	size_t lenStr = wcslen(str);
	size_t lenToken = wcslen(token);
	if (lenStr < lenToken){ return false; }
	for(size_t i=0; i<lenToken; ++i){
		if (str[i] != token[i]){ return false; }
	}
	return true;
}


std::wstring Helper::ComboPath(const wchar_t * str1, const wchar_t * str2)
{
	_ASSERT(str1 != NULL && str2 != NULL);
	wchar_t result[MAX_PATH];
	errno_t err = wcscpy_s(result, MAX_PATH, str1); if (err != 0){ _ASSERT(false); return L""; }
	size_t len = wcslen(result); if (len >= MAX_PATH - 2){ _ASSERT(false); return L""; }
	wchar_t * endOfStr1; size_t size;
	if (result[len-1] != L'/' && result[len-1] != L'\\'){ 
		result[len] = L'\\';
		endOfStr1 = result + len + 1;
		size = MAX_PATH - len - 1;
	} else {
		endOfStr1 = result + len;
		size = MAX_PATH - len;
	}
	const wchar_t * _str2 = (str2[0] == L'/' || str2[0] == L'\\') ? str2+1 : str2;
	err = wcscpy_s(endOfStr1, size, _str2); if (err != 0){ _ASSERT(false); return L""; }
	return result;
}

bool Helper::IsDirectory(const wchar_t *pDir)
{
	wchar_t szCurPath[MAX_PATH];
	ZeroMemory(szCurPath, sizeof(wchar_t) * MAX_PATH);
	swprintf_s(szCurPath, MAX_PATH, L"%s//*", pDir);
	WIN32_FIND_DATA FindFileData;		
	ZeroMemory(&FindFileData, sizeof(WIN32_FIND_DATA));

	HANDLE hFile = FindFirstFile(szCurPath, &FindFileData); /**< find first file by given path. */

	if( hFile == INVALID_HANDLE_VALUE )	
	{
		FindClose(hFile);
		return false; /** ��������ҵ���һ���ļ�����ôû��Ŀ¼ */
	}else
	{	
		FindClose(hFile);
		return true;
	}

}

bool Helper::DeleteDirectory(const wchar_t * DirName)
{
	//	CFileFind tempFind;		//����һ��CFileFind�����������������
	wchar_t szCurPath[MAX_PATH];		//���ڶ���������ʽ
	_snwprintf_s(szCurPath, MAX_PATH, L"%s//*.*", DirName);	//ƥ���ʽΪ*.*,����Ŀ¼�µ������ļ�
	WIN32_FIND_DATA FindFileData;		
	ZeroMemory(&FindFileData, sizeof(WIN32_FIND_DATA));
	HANDLE hFile = FindFirstFile(szCurPath, &FindFileData);
	BOOL IsFinded = TRUE;
	while(IsFinded)
	{
		IsFinded = FindNextFile(hFile, &FindFileData);	//�ݹ������������ļ�
		if( wcscmp(FindFileData.cFileName, L".") && wcscmp(FindFileData.cFileName, L"..") ) //�������"." ".."Ŀ¼
		{
			std::wstring strFileName = L"";
			strFileName = strFileName + DirName + L"//" + FindFileData.cFileName;
			std::wstring strTemp;
			strTemp = strFileName;
			if( IsDirectory(strFileName.c_str()) ) //�����Ŀ¼����ݹ�ص���
			{	
				// printf("Ŀ¼Ϊ:%s/n", strFileName.c_str());
				DeleteDirectory(strTemp.c_str());
			}
			else
			{
				DeleteFile(strTemp.c_str());
			}
		}
	}
	FindClose(hFile);

	BOOL bRet = RemoveDirectory(DirName);
	if( bRet == FALSE ) //ɾ��Ŀ¼
	{
		// printf("ɾ��%sĿ¼ʧ�ܣ�/n", DirName);
		return false;
	}
	return true;
}

std::wstring Helper::CopyDirectory(const wchar_t * fullFilenameSrc, const wchar_t * fullFilenameDst)
{
    return L"";
}

std::wstring Helper::GetFilename(const wchar_t * fullFilename)
{
	size_t len = wcslen(fullFilename);
	size_t i = 0;
	for(; i<len; ++i){
		const wchar_t & c = fullFilename[len - i - 1];
		if (c == L'\\' || c == L'/'){
			break;
		}
	}
	return fullFilename + (len - i);
}

static bool FindFirstFileExists(const wchar_t * lpPath, DWORD dwFilter)
{
	WIN32_FIND_DATA fd;
	HANDLE hFind = FindFirstFile(lpPath, &fd);
	BOOL bFilter = (FALSE == dwFilter) ? TRUE : fd.dwFileAttributes & dwFilter;
	bool RetValue = ((hFind != INVALID_HANDLE_VALUE) && bFilter) ? true : false;
	FindClose(hFind);
	return RetValue;
}

bool Helper::FilePathExists(const wchar_t * directory)
{
	return FindFirstFileExists(directory, FALSE);
}

bool Helper::DirectoryExists(const wchar_t * directory)
{
	return FindFirstFileExists(directory, FALSE);
}