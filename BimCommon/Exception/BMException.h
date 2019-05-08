#pragma once

/**
 *  @description : 定义自己的异常类
 *  @author : wangjl
 *  @date : 2019/04/28
 */

#include <exception>
#include <QString>
#include "BMGlobal.h"

namespace BMCOMMON
{

#define THROWBMEXCEPTION(info) throw BMException(\
QString("file  : %1\nfunc  : %2\nline  : %3\ninfo  : %4").arg(__FILE__).arg(__FUNCTION__).arg(__LINE__).arg(info));

	class BIMCOMMON_EXPORT BMException : public std::exception
	{
	public:
		explicit BMException();
		explicit BMException(const char * const & e);
		explicit BMException(const QString & e);

		virtual ~BMException();
	};
}


