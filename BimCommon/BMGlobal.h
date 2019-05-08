#pragma once


#ifdef BIMCOMMON_LIB
# define BIMCOMMON_EXPORT Q_DECL_EXPORT
#else
# define BIMCOMMON_EXPORT Q_DECL_IMPORT
#endif


