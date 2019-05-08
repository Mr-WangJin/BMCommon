#include "stdafx.h"
#include "SyncCloudTProxy.h"
#include "SyncServer.h"
#include "Exception/BMException.h"
#include "SyncTableBase.h"
#include "SyncCloudTable.h"

using namespace BIMCOMMON;
using namespace Synchronization;

BIMCOMMON::SyncCloudTProxy::SyncCloudTProxy(const SyncProjectInfo &projectInfo)
	: SyncProxyBase(projectInfo)
{
}

BIMCOMMON::SyncCloudTProxy::~SyncCloudTProxy()
{
}
