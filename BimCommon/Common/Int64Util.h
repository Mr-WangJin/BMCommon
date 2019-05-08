#pragma once

#include <string>
#include <algorithm>
#include <xfunctional>

#define I_INVALID_HANDLE 0

class Int64Util
{
public:
	//��ʼ����ѯ�����κ�NewID()֮ǰ����
	static void InitSeed();

	//�����µ�OBjectID
	static unsigned long long NewID();

	static unsigned long long NewID(std::string & seed);

	//�����µ�OBjectID, �����׵� ID, Ϊ�� ����32λ����ID ����
	static unsigned int NewID32();
};

struct Helper
{
	static std::wstring GetExecutePath();

	// ���ص��� Windows �ļ� Handle, ��Ҫ���� CloseHandle �ر��ļ�
	static void * CreateWin32TempFile(std::wstring & out_filename);

	// ���һ����ʱ�ļ���, ���������ļ�
	static std::wstring GetTempFilename();

	// ���һ����ʱ�ļ���, ���������ļ�
	static std::wstring GetTempName();

	// ����û���ʱĿ¼
	static std::wstring GetUserTempDirectory();

	// ���������һ����ʱĿ¼
	static std::wstring GetTempDirectory();

	static bool StrEndWith(const wchar_t * str, const wchar_t * token);
	static bool StrStartWith(const wchar_t * str, const wchar_t * token);

	// �ϲ�·��
	static std::wstring ComboPath(const wchar_t * str1, const wchar_t * str2);

	// �ϲ�·��
	static std::wstring GetFilename(const wchar_t * fullFilename);

	// 
	static bool IsDirectory(const wchar_t *pDir);

	static bool DeleteDirectory(const wchar_t * DirName);

    static std::wstring CopyDirectory(const wchar_t * fullFilenameSrc, const wchar_t * fullFilenameDst);

	static bool DirectoryExists(const wchar_t * directory);

	// ���һ��  ·�� �Ƿ���ڣ�����·�������·�����ļ����ļ��о��ɣ�
	static bool FilePathExists(const wchar_t * directory);

	static inline std::wstring & lTrim(std::wstring & ss)   
	{   
		std::wstring::iterator p = std::find_if(ss.begin(),ss.end(), std::not1(std::ptr_fun(iswspace)));   
		ss.erase(ss.begin(),p);   
		return ss;   
	}   

	static inline std::wstring & rTrim(std::wstring & ss)   
	{   
		std::wstring::reverse_iterator p=std::find_if(ss.rbegin(),ss.rend(),std::not1(std::ptr_fun(iswspace)));   
		ss.erase(p.base(),ss.end());   
		return ss;   
	}   

	static inline std::wstring & trim(std::wstring   &st)   
	{   
		lTrim(rTrim(st));   
		return st;   
	} 
};

