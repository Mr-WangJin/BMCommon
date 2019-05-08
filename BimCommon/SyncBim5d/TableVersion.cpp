#include "stdafx.h"
#include "TableVersion.h"
#include "CascadeNode.h"
#include "RequestData.h"
#include "json/value.h"
#include "json/reader.h"
#include "SyncProxyBase.h"
#include "Exception/BMException.h"
#include "ServiceConfig.h"
#include "SyncCloudTable.h"
#include "SyncServer.h"
#include "Error/SyncError.h"
#include "SyncCloudTProxy.h"
#include "SyncCloudTable.h"

using namespace Synchronization;

using namespace std;
using namespace BIMCOMMON;

TableVersion::TableVersion(SyncProxyBasePtr syncProxy)
	: m_syncProxy(syncProxy)
	, m_updateAllTable(false)
{
	assert(m_syncProxy);

	SyncServer::ProjectInfo projInfo;
	projInfo.loginToken = m_syncProxy->getProjectInfo().getToken();
	projInfo.projectID = m_syncProxy->getProjectInfo().getProjectID();
	m_syncServer = QSharedPointer<Synchronization::SyncServer>(new SyncServer(projInfo));

	m_syncTable = SyncCloudTablePtr(new SyncCloudTable(m_syncProxy));
}

TableVersion::~TableVersion()
{
	
}

void TableVersion::addSyncTable(SyncTableBasePtr syncTable)
{
	QString tableName = syncTable->getTableName();
	m_syncTableMap[tableName] = syncTable;
}

void TableVersion::updateTableVersion()
{
	try
	{
		m_syncProxy->beginSyncTable();
		
		QVector<SyncServer::UpdateTableInfo> updateTableInfos;
		SyncServer::ProjectInfo projInfo;
		projInfo.loginToken = m_syncProxy->getProjectInfo().getToken();
		projInfo.projectID = m_syncProxy->getProjectInfo().getProjectID();

		Synchronization::SyncServer server(projInfo);
		QList<QPair<QString, qint64>> tableVersionList;
		if (server.getAllTableVersionList(tableVersionList) == false)
		{
			THROWBMEXCEPTION(QStringLiteral("获取表版本号失败！"));
		}

		GSPTable tbVersion = m_syncProxy->getTable("TableVersion");
		for each (auto var in tableVersionList)
		{
			GSPRecord tbRecord = tbVersion.locateEx(QString("(RemoteType = 1) and (RemoteTableName = '%1')").arg(var.first));
			if (tbRecord == nullptr)
				continue;
			tbRecord.setAsUInt64("RemoteVersion", var.second);
		}

		m_syncProxy->endSyncTable();
	}
	catch (BMException &e)
	{
		m_syncProxy->rollback();
		throw e;
	}
	catch (...)
	{
		m_syncProxy->rollback();
		THROWBMEXCEPTION(QStringLiteral("未知异常，数据已回滚！"));
	}
}

bool TableVersion::isNeedUpdate()
{
	this->updateTableVersion();

	GSPTable tbVersion = m_syncProxy->getTable("TableVersion");
	GSPRecordList tbRecordList = tbVersion.createRecordList(QString("(RemoteType = 1)"));
	for (int i = 0; i < tbRecordList.count(); ++i)
	{
		GSPRecord rec = tbVersion[i];
		if (rec.asUInt64("LocalVersion") != rec.asUInt64("RemoteVersion"))
			return true;
	}
	return false;
}

void TableVersion::cascadeUpdateTable(const QString & tableName)
{
	if (tableName.isEmpty())
	{
		THROWBMEXCEPTION("param error!");
	}

	//构建级联树
	QVector<QString> tableVec;	//防止递归无限循环
	GSPTable tbVersion = m_syncProxy->getVersionTable();
	std::function<void(CascadeNode*, const QString &)> iterFoerignTable;
	iterFoerignTable = [&](CascadeNode* node, const QString &tableName) 
	{
		node->setUserData(tableName);
		tableVec.push_back(tableName);
		GSPTable table = m_syncProxy->getTable(tableName);
		GSPFieldSchemas tableSchemas = table.tableSchema().fieldSchemas();
		for (int i = 0; i < tableSchemas.count(); ++i)
		{
			if (tableSchemas[i].fieldKind() == fkForeignKey)
			{
				GSPForeignKeyFieldSchema foreignFieldSchema = tableSchemas[i];
				if (!foreignFieldSchema)
					continue;
				QString master = foreignFieldSchema.masterTableName();
				if (tableVec.contains(master))
					continue;

				CascadeNode* cNode = new CascadeNode();
				node->addChild(cNode);
				iterFoerignTable(cNode, master);
			}
		}
	};

	std::shared_ptr<CascadeNode> root(new CascadeNode());
	iterFoerignTable(root.get(), tableName);

	//后序遍历树
	std::function<void(CascadeNode*)> iterTree;
	iterTree = [&](CascadeNode* node)
	{
		if (node->hasChild())
		{
			for each (auto &var in node->getChild())
			{
				iterTree(var);
			}
		}
		this->updateTable(node->getUserData().toString());
	};

	try
	{
		m_syncProxy->beginSyncTable();
		iterTree(root.get());
		m_syncProxy->endSyncTable();
	}
	catch (BMException &e)
	{
		m_syncProxy->rollback();
		throw e;
	}
	catch (GLDException &e)
	{
		m_syncProxy->rollback();
		throw e;
	}
	catch (...)
	{
		m_syncProxy->rollback();
		THROWBMEXCEPTION(QString("Unknow error, cascadeUpdateTable udpate table %1").arg(tableName));
	}
}

void TableVersion::updateAllTable()
{
	try
	{
		m_updateAllTable = true;
		if (m_alreadyUpdateTable.isEmpty() == false)
			m_alreadyUpdateTable.clear();

		emit beginSyncModel();

		QVector<SyncServer::UpdateTableInfo> updateTableInfos;
		GSPTable tableVersion = m_syncProxy->getTable("TableVersion");
		GSPRecordList rList = tableVersion.createRecordList(QString("RemoteType = 1"));
		for (int i = 0; i < rList.count(); ++i)
		{
			SyncServer::UpdateTableInfo tableInfo;
			tableInfo.tableName = rList[i].asString("RemoteTableName");
			tableInfo.localTableRevision = 0;
			updateTableInfos.append(tableInfo);
		}

		m_syncServer->UpdateTableData(updateTableInfos);
		if (m_syncServer->GetLastError() != nullptr)
		{
			QString error = QString("%1, %2, %3").arg(m_syncServer->GetLastError()->message())
				.arg(m_syncServer->GetLastError()->file_name()).arg(m_syncServer->GetLastError()->line());
			THROWBMEXCEPTION(error);
		}

		for (int i = 0; i < rList.count(); ++i)
		{
			this->cascadeUpdateTable(rList[i].asString("TableName"));
		}

		m_updateAllTable = false; 
		emit endSyncModel();
	}
	catch (BMException &e)
	{
		m_updateAllTable = false;
		throw e;
	}
	catch (GLDException &e)
	{
		m_updateAllTable = false;
		throw e;
	}
	catch (...)
	{
		m_updateAllTable = false;
		THROWBMEXCEPTION(QStringLiteral("未知异常，数据已回滚"));
	}
}

void TableVersion::updateTable(const QString & tableName)
{
	assert(!tableName.isEmpty() && "table name is empty");

	//更新全部表使用
	if (m_updateAllTable && m_alreadyUpdateTable.contains(tableName))
	{
		return;
	}
	m_alreadyUpdateTable.push_back(tableName);

	GSPTable tableVersion = m_syncProxy->getVersionTable();
	GSPRecord tableVersionR = tableVersion.locateEx(QString("TableName = '%1'").arg(tableName));
	if (tableVersionR == nullptr)
	{
		return;
		THROWBMEXCEPTION(QStringLiteral("级联更新表中，检查到表版本没有添加表%1").arg(tableName));
	}
	if (tableVersionR.asString("LocalFullHashValue") == tableVersionR.asString("RemoteFullHashValue") &&
		tableVersionR.asUInt64("LocalVersion") == tableVersionR.asUInt64("RemoteVersion"))
		return;

	m_syncTable->setTableName(tableName);
	switch ((SyncType)tableVersionR.asInteger("SyncType"))
	{
	case IncrementType:
	{
		QString remoteTableName = tableVersionR.asString("RemoteTableName");
 		TablePtr tableData = m_syncServer->getTableData(remoteTableName);
 		m_syncTable->syncTableRecord(tableData);
		m_syncTable->updateLocalRemoteVersion(tableVersionR.asUInt64("RemoteVersion"));
	}
	break;
	default:
		break;
	}
}

