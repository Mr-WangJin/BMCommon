#pragma once

/**
*	ͬ��BIM5D���ݴ����࣬��Ҫ������Ӧ����
*	���߳�ͬ��
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

