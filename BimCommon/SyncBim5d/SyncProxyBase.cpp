#include "stdafx.h"
#include "SyncProxyBase.h"
#include "Common/BMGSPCommon.h"
#include "Exception/BMException.h"
#include "GLDFileUtils.h"

using namespace BIMCOMMON;

SyncProxyBase::SyncProxyBase(const SyncProjectInfo & projectInfo)
	: QObject()
	, m_projectInfo(projectInfo)
{
// 	assert(!m_token.isEmpty() && "token is null");
// 	assert(!m_projectID.isEmpty() && "project id is null");
}

SyncProxyBase::~SyncProxyBase()
{
}


QString SyncProxyBase::getFullUrl(GSPRecord tableVersionR)
{
	QString url;
	if (tableVersionR.asBoolean("IsGZip"))
		url = QString("%1projects/%2/cost/gquery").arg(m_projectInfo.getCloudServiceV1()).arg(m_projectInfo.getProjectID());
	else
		url = QString("%1projects/%2/cost/query").arg(m_projectInfo.getCloudServiceV1()).arg(m_projectInfo.getProjectID());
	return url;
}

void SyncProxyBase::loadGSPModel(const QString & modelFileName)
{
	if (m_modelFileName == modelFileName)
		return;
	m_modelFileName = modelFileName;
	if (fileExists(m_modelFileName))
	{
		BIMCOMMON::LoadGSPModel(m_model, m_modelFileName);
		if (m_model == nullptr)
		{
			throw BIMCOMMON::BMException(QString("load Bim5dModel.GSP error"));
		}
	}
	else
	{
		THROWBMEXCEPTION(QString("could not find %1").arg(m_modelFileName));
	}

}

GSPModel SyncProxyBase::getModel()
{
	return m_model;
}

void SyncProxyBase::setProjectInfo(const SyncProjectInfo & projectInfo)
{
	m_projectInfo = projectInfo;
}

const SyncProjectInfo &SyncProxyBase::getProjectInfo() const
{
	return m_projectInfo;
}

// void BIMCOMMON::SyncProxyBase::setModel(GSPModel model)
// {
// 	m_model = model;
// }

void SyncProxyBase::saveModel()
{
	GSPModelPersistent(m_model).saveToFile(m_modelFileName, false, false);
}

GSPTable SyncProxyBase::getTable(const QString &tableName, const QString &dbName)
{
	if (m_model != nullptr)
		return m_model.tableByName(tableName, dbName);
	
	return nullptr;
}

GSPTable SyncProxyBase::getVersionTable(const QString &dbName/* = "DB"*/)
{
	if (m_model != nullptr)
		return m_model.tableByName("TableVersion", dbName);

	return nullptr;
}

void SyncProxyBase::beginSyncTable()
{
	m_model.beginTransaction();
	m_model.beginUpdate();
	m_model.beginPauseEvents();
}

void SyncProxyBase::endSyncTable()
{
	m_model.endPauseEvents();
	m_model.endUpdate();
	m_model.endTransaction();
}

void SyncProxyBase::rollback()
{
	m_model.endPauseEvents();
	m_model.endUpdate();
	m_model.rollback();
}

