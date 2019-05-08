#pragma once

#include <string>
#include <algorithm>
#include <xfunctional>

#define I_INVALID_HANDLE 0

class Int64Util
{
public:
	//初始化查询表，在任何NewID()之前调用
	static void InitSeed();

	//生成新的OBjectID
	static unsigned long long NewID();

	static unsigned long long NewID(std::string & seed);

	//生成新的OBjectID, 不靠谱的 ID, 为了 兼容32位整型ID 考虑
	static unsigned int NewID32();
};

struct Helper
{
	static std::wstring GetExecutePath();

	// 返回的是 Windows 文件 Handle, 需要调用 CloseHandle 关闭文件
	static void * CreateWin32TempFile(std::wstring & out_filename);

	// 获得一个临时文件名, 但不创建文件
	static std::wstring GetTempFilename();

	// 获得一个临时文件名, 但不创建文件
	static std::wstring GetTempName();

	// 获得用户临时目录
	static std::wstring GetUserTempDirectory();

	// 创建并获得一个临时目录
	static std::wstring GetTempDirectory();

	static bool StrEndWith(const wchar_t * str, const wchar_t * token);
	static bool StrStartWith(const wchar_t * str, const wchar_t * token);

	// 合并路径
	static std::wstring ComboPath(const wchar_t * str1, const wchar_t * str2);

	// 合并路径
	static std::wstring GetFilename(const wchar_t * fullFilename);

	// 
	static bool IsDirectory(const wchar_t *pDir);

	static bool DeleteDirectory(const wchar_t * DirName);

    static std::wstring CopyDirectory(const wchar_t * fullFilenameSrc, const wchar_t * fullFilenameDst);

	static bool DirectoryExists(const wchar_t * directory);

	// 检查一个  路径 是否存在（绝对路径、相对路径，文件或文件夹均可）
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

