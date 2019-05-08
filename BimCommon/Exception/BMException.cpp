#include "stdafx.h"
#include "BMException.h"

using namespace BMCOMMON;


BMCOMMON::BMException::BMException()
	: std::exception()
{
}

BMCOMMON::BMException::BMException(const char * const & e)
	: std::exception(e)
{
}

BMException::BMException(const QString & e)
	: std::exception(e.toStdString().c_str())
{

}


BMCOMMON::BMException::~BMException()
{
}
