#pragma once

/**
*	同步BIM5D数据代理类，需要设置相应参数
*	单线程同步
*/

#include <QObject>
#include "SyncBim5d/SyncProxyBase.h"
#include "json/value.h"

namespace BIMCOMMON
{
	class BIMCOMMON_EXPORT SyncCloudTProxy : public SyncProxyBase
	{
		Q_OBJECT
	public:
		SyncCloudTProxy(const SyncProjectInfo &projectInfo);
		virtual ~SyncCloudTProxy();
	};


}

