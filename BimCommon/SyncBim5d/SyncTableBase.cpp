#include "stdafx.h"
#include "SyncTableBase.h"
#include "SyncProxyBase.h"
#include "Exception/BMException.h"
#include "Common/BMGSPCommon.h"
#include "CascadeNode.h"
#include "BMDefine.h"

using namespace BIMCOMMON;

SyncTableBase::SyncTableBase(SyncProxyBasePtr proxy, QObject * parent)
	: QObject(parent)
	, m_syncProxy(proxy)
{
	assert(proxy);


}

SyncTableBase::~SyncTableBase()
{
}

void BIMCOMMON::SyncTableBase::setTableName(const QString & tableName)
{
	m_tableName = tableName;
	m_table = m_syncProxy->getTable(m_tableName);
	m_primaryKey = m_table.tableSchema().primaryKey();

	GSPTable tableVersion = m_syncProxy->getTable("TableVersion");
	m_tableVersionR = tableVersion.locateEx(QString("TableName = '%1'").arg(m_tableName));
	assert(m_tableVersionR);

	this->initMineField();
}

const QString & SyncTableBase::getTableName() const
{
	return m_tableName;
}

void SyncTableBase::addRecord(const Json::Value &r)
{
	int toRemoteFieldType = m_tableVersionR.asInteger("ToRemoteFieldType");

	switch (toRemoteFieldType)
	{
	case Alias_Type:
	{
		GSPRecord newR = m_table.newRecord();
		for (int i = 0; i < newR.fieldCount(); ++i)
		{
			setFieldValue(newR.fields(i), r);
		}
		m_table.append(newR);
		this->afterAddedRecord(newR);
	}
		break;
	case Customize_Type:
	{
		GSPRecord newR = m_table.newRecord();
		GSPRecordList toRemoteFieldList = m_tableVersionR.detailRecords("ToRemoteField");
		for (int i = 0; i < toRemoteFieldList.count(); ++i)
		{
			GSPRecord toRemoteFieldRecord = toRemoteFieldList[i];
			QString localFieldName = toRemoteFieldRecord.asString("LocalFieldName");
			QString remoteFieldName = toRemoteFieldRecord.asString("RemoteFieldName");
			std::string sRemoteFieldName = remoteFieldName.toStdString();
			if (r[sRemoteFieldName].isNull())
				continue;
			this->setFieldValue(newR.fieldByName(localFieldName), r);
		}
		m_table.append(newR);
		this->afterAddedRecord(newR);
	}
		break;
	default:
		assert(1 == 0 && "No Fit ToRemoteFieldType");
		break;
	}
	
}

void SyncTableBase::removeRecord(const Json::Value &r)
{
	GSPTable tbCostToRemoteField = m_syncProxy->getTable("ToRemoteField");
	ToRemoteFieldType toRemoteFieldType = (ToRemoteFieldType)m_tableVersionR.asInteger("ToRemoteFieldType");
	switch (toRemoteFieldType)
	{
	case Alias_Type:
	{
		GSPFieldSchema primaryField = m_table.tableSchema().findFieldSchema(m_primaryKey);
		std::string aliasName = primaryField.aliasName().remove(0, 1).toStdString();
		//assert(r[aliasName].isNull() == false && "no remote field name");
		if (r[aliasName].isNull())
			return;
		quint64 primaryID =stringToNum<quint64>(r[aliasName].asString());
		GSPRecord record = m_table.findByID64(primaryID);
		if (record)
		{
			m_table.remove(record);
		}
	}
		break;
	case Customize_Type:
	{
		GSPRecord costToRemoteFieldR = tbCostToRemoteField.locateEx(
			QString("(CostTableVersionID = %1) and (FieldType = 2)").arg(m_tableVersionR.id64()));

		QString localFieldName = costToRemoteFieldR.asString("LocalFieldName");
		QString remoteFieldName = costToRemoteFieldR.asString("RemoteFieldName");
		std::string sRemoteFieldName = remoteFieldName.toStdString();

		assert(r[sRemoteFieldName].isNull() == false && "no remote field name");
		if (r[sRemoteFieldName].isNull())
			return;
		quint64 primaryID = stringToNum<quint64>(r[sRemoteFieldName].asString());
		GSPRecord record = m_table.findByID64(primaryID);
		if (record)
		{
			m_table.remove(record);
		}
	}
	break;
	default:
		assert(1 == 0 && "No Fit ToRemoteFieldType");
		break;
	}
}

void SyncTableBase::updateRecord(const Json::Value &r)
{
	int toRemoteFieldType = m_tableVersionR.asInteger("ToRemoteFieldType");
	switch (toRemoteFieldType)
	{
	case Alias_Type:
	{
		GSPFieldSchema primaryField = m_table.tableSchema().findFieldSchema(m_primaryKey);
		QString primaryAliasName = primaryField.aliasName();
		if (primaryAliasName.isEmpty())
		{
			THROWBMEXCEPTION(QStringLiteral("%1 表，主键别名不能为空").arg(m_tableName));
		}
		primaryAliasName = primaryAliasName.remove(0, 1);
		std::string primaryAliasStr = primaryAliasName.toStdString();
		quint64 primaryID = stringToNum<quint64>(r[primaryAliasStr].asString());
		GSPRecord record = m_table.findByID64(primaryID);
		if (record == nullptr)
		{
			THROWBMEXCEPTION(QStringLiteral("%1 表 找不到主键ID %2").arg(m_tableName).arg(primaryID));
		}

		for (int i = 0; i < record.fieldCount(); ++i)
		{
			GSPField field = record.fields(i);
			if (field.fieldKind() == fkPrimaryKey)
				continue;
			this->setFieldValue(field, r);
		}
	}
	break;
	case Customize_Type:
	{
		GSPTable tbToRemoteField = m_syncProxy->getTable("ToRemoteField");
		GSPRecord toRemoteFieldR = tbToRemoteField.locateEx(
			QString("(TableVersionID = %1) and (FieldType = 2)").arg(m_tableVersionR.id64()));

		QString localFieldName = toRemoteFieldR.asString("LocalFieldName");
		QString remoteFieldName = toRemoteFieldR.asString("RemoteFieldName");
		std::string sRemoteFieldName = remoteFieldName.toStdString();

		if (r[sRemoteFieldName].isNull())
			break;
		quint64 primaryID = stringToNum<quint64>(r[sRemoteFieldName].asString());
		GSPRecord record = m_table.findByID64(primaryID);
		if (record == nullptr)
		{
			THROWBMEXCEPTION(QStringLiteral("%1 表 找不到主键ID %2").arg(m_tableName).arg(primaryID));
		}
		
		GSPRecordList toRemoteFieldList = m_tableVersionR.detailRecords("CostToRemoteField");
		for (int i = 0; i < toRemoteFieldList.count(); ++i)
		{
			GSPRecord toRemoteFieldRecord = toRemoteFieldList[i];
			QString localFieldName = toRemoteFieldRecord.asString("LocalFieldName");
			QString remoteFieldName = toRemoteFieldRecord.asString("RemoteFieldName");
			std::string sRemoteFieldName = remoteFieldName.toStdString();
			if (r[sRemoteFieldName].isNull())
				continue;

			this->setFieldValue(record.fieldByName(localFieldName), r);
		}
	}
	break;
	default:
		assert(1 == 0 && "No Fit ToRemoteFieldType");
		break;
	}
}

void SyncTableBase::setFieldValue(GSPField& field, const Json::Value &v)
{
#ifdef _DEBUG
	QString aa = QString::fromStdString(v.toStyledString());
#endif // _DEBUG

	QString aliasName = field.aliasName();
	if (aliasName.isEmpty())
		return;
	std::string aliasNameStr = aliasName.remove(0, 1).toStdString();
	QVariant var = this->getJsonValueAsVariant(v, aliasNameStr);
	if (var.isNull())
		return;
	GSPDataType dt = field.dataType();
	switch (dt)
	{
	case dtString:
	case dtText:
	{
		field.setAsVariant(var);
	}
	break;
	case dtDateTime:
	{
		quint64 timeCount = var.toULongLong();
		QString dateStr = QDateTime::fromMSecsSinceEpoch(timeCount).toString(Qt::ISODate);
		field.setAsString(dateStr);
	}
	break;
	case dtLongInt:
	case dtInt64:
	{
		field.setAsInteger(var.toLongLong());
	}
	break;
	case dtShortInt:
	case dtSmallInt:
	{
		field.setAsInteger(var.toInt());
	}
	break;
	case dtDouble:
	case dtDecimal:
	{
		field.setAsFloat(var.toDouble());
	}
	break;
	case dtUInt64:
	{
		quint64	id = stringToNum<quint64>(var.toString().toStdString());
		if (id > 0)
			field.setAsUInt64(id);
	}
	break;
	default:
		break;
	}
}

QVariant SyncTableBase::getJsonValueAsVariant(const Json::Value &v, const std::string & key)
{
	switch (v[key].type())
	{
	case Json::nullValue :
		return QVariant();
		break;
	case Json::intValue:
		return QVariant(v[key].asInt());
		break;
	case Json::uintValue:
		return QVariant(v[key].asUInt64());
		break;
	case Json::realValue:
		return QVariant(v[key].asDouble());
		break;
	case Json::stringValue:
		return QVariant(v[key].asCString());
		break;
	case Json::booleanValue:
		return QVariant(v[key].asBool());
		break;
	case Json::arrayValue:
		break;
	case Json::objectValue:
		break;
	default:
		break;
	}
	return QVariant();
}

quint64 SyncTableBase::getValuePrimaryID(const Json::Value &r)
{
	quint64 primaryId = 0;
	ToRemoteFieldType toRemoteFieldType = (ToRemoteFieldType)m_tableVersionR.asInteger("ToRemoteFieldType");
	switch (toRemoteFieldType)
	{
	case BIMCOMMON::Alias_Type:
	{
		QString aliasName = m_table.tableSchema().findFieldSchema(m_primaryKey).aliasName();
		std::string aliasNameStr = aliasName.remove(0, 1).toStdString();
		if (r[aliasNameStr].isNull())
			THROWBMEXCEPTION(QString("not find alias field %1").arg(aliasName));

		primaryId = stringToNum<quint64>(r[aliasNameStr].asString());
	}
	break;
	case BIMCOMMON::Customize_Type:
	{
		GSPTable tbToRemoteField = m_syncProxy->getTable("ToRemoteField");
		QString filter = QString("(TableVersionID = %1) and (FieldType = 2)");
		GSPRecordList toRemoteFieldList = tbToRemoteField.createRecordList(filter);
		if (toRemoteFieldList.count() != 1)
			THROWBMEXCEPTION(QString("could not find primary key!"));

		QString aliasName = toRemoteFieldList[0].asString("RemoteFieldName");
		if (r[aliasName.toStdString()].isNull())
			THROWBMEXCEPTION(QString("cloud not find alias field %1").arg(aliasName));

		primaryId = stringToNum<quint64>(r[aliasName.toStdString()].asString());
	}
	break;
		break;
	default:
		break;
	}
	return primaryId;
}

void SyncTableBase::initMineField()
{
	//if (m_tableVersionR.asInteger("SyncType") == FullType)
	{
		if (m_tableVersionR.asInteger("ToRemoteFieldType") == Customize_Type)
		{
			GSPTable tbCostToRemoteField = m_syncProxy->getTable("ToRemoteField");
			GSPRecord costToRemoteFieldR = tbCostToRemoteField.locateEx(
				QString("(CostTableVersionID = %1) and (FieldType = 3)").arg(m_tableVersionR.id64()));
			if (costToRemoteFieldR != nullptr)
			{

			}
		}
		else if (m_tableVersionR.asInteger("ToRemoteFieldType") == Alias_Type)
		{
			QString tableName = m_table.name();
			GSPFieldSchemas fields = m_table.tableSchema().fieldSchemas();
			for (int i = 0; i < fields.count(); ++i)
			{
				GSPFieldSchema field = fields[i];
				if (field.fieldKind() == fkForeignKey)
				{
					GSPForeignKeyFieldSchema foreignFieldSchema = field;
					if (!foreignFieldSchema)
						continue;
					QString master = foreignFieldSchema.masterTableName();
					if (master == tableName)
					{
						m_toMineField.insert(field.fieldName(), field.aliasName().remove(0, 1).toStdString());
						break;
					}
				}
			}
		}
	}
}

void SyncTableBase::addNoUsedFieldName(const QString &fieldName)
{
	if (m_noUsedFieldName.contains(fieldName))
		return;
	m_noUsedFieldName.push_back(fieldName);
}

void SyncTableBase::removeNoUsedFieldName(const QString &fieldName)
{
	if (!m_noUsedFieldName.contains(fieldName))
		return;
	m_noUsedFieldName.removeOne(fieldName);
}

void SyncTableBase::clearNoUsedFieldName()
{
	m_noUsedFieldName.clear();
}

void SyncTableBase::updateLocalRemoteVersion(const quint64 &version)
{
	//assert(m_tableVersionR.asUInt64("RemoteVersion") >= version);
	m_tableVersionR.setAsUInt64("LocalVersion", version);
	//m_tableVersionR.setAsUInt64("RemoteVersion", version);
}

void SyncTableBase::setLocalFullHashValue(const QString &hash)
{
	m_tableVersionR.setAsString("LocalFullHashValue", hash);
}

void SyncTableBase::setTableChanged(bool changed)
{
	m_tableChanged = changed;
}

void SyncTableBase::syncTableRecord(const Json::Value &v)
{
	m_tableChanged = true;

	QString action = v["action"].asString().c_str();
	if (action == "delete")
	{
		this->removeRecord(v);
		return;
	}

	quint64 primaryId = this->getValuePrimaryID(v);
	if (m_toMineField.size() > 0)
	{
		//如果当前表存在指向自己的外键，则特殊处理
		std::string aliasName = m_toMineField.begin().value();
		if (!v[aliasName].isNull() && v[aliasName].asString() != "0" &&
			!m_table.findByID64(stringToNum<quint64>(v[aliasName].asString())))
		{
			if (action == "create" || m_table.findByID64(primaryId) == nullptr)
			{
				m_needAddedList.insert(primaryId, v);
			}
			else if (action == "update")
			{
				m_needUpdateList.insert(primaryId, v);
			}
			return;
		}
	}

	if (action == "create" || m_table.findByID64(primaryId) == nullptr)
	{
		this->addRecord(v);
	}
	else if (action == "update")
	{
		this->updateRecord(v);
	}
}

void SyncTableBase::beginSyncTable()
{
	m_needAddedList.clear();
	m_needUpdateList.clear();

	m_tableChanged = false;
}

void SyncTableBase::endSyncTable()
{
	if (m_tableChanged == false)
		return;

	if (m_toMineField.count() > 0)
	{
		size_t count = 0;
		std::string aliasName = m_toMineField.begin().value();
		while (m_needAddedList.count() > 0)
		{
			count = m_needAddedList.count() + m_needUpdateList.count();
			QMap<quint64, Json::Value>::iterator iter = m_needAddedList.begin();
			QMap<quint64, Json::Value>::iterator tempIter;
			for (; iter != m_needAddedList.end();)
			{
				tempIter = iter;
				++iter;
				quint64 foreignID = stringToNum<quint64>(tempIter.value()[aliasName].asString());
				if (m_table.findByID64(foreignID))
				{
					this->addRecord(tempIter.value());
					m_needAddedList.erase(tempIter);
				}
			}
			iter = m_needUpdateList.begin();
			for (; iter != m_needUpdateList.end();)
			{
				tempIter = iter;
				++iter;
				quint64 foreignID = stringToNum<quint64>(tempIter.value()[aliasName].asString());
				if (m_table.findByID64(foreignID))
				{
					this->updateRecord(tempIter.value());
					m_needUpdateList.erase(tempIter);
				}
			}
			if (count == m_needAddedList.count() + m_needUpdateList.count())
			{
				THROWBMEXCEPTION(QStringLiteral("%1表，获取的全量数据，有部分数据添加不到数据库中"));
			}
		}
	}
}

void SyncTableBase::syncFullTableRecord(const Json::Value &v)
{
#ifdef _DEBUG
	QString aa = QString::fromStdString(v.toStyledString());
#endif // _DEBUG

	quint64 primaryId = this->getValuePrimaryID(v);

	if (m_needRemoveList.contains(primaryId))
	{
		this->updateRecord(v);
		m_needRemoveList.remove(primaryId);
	}
	else
	{
		if (m_toMineField.count() == 0)
		{
			this->addRecord(v);
		}
		else
		{
			std::string aliasName = m_toMineField.begin().value();
			QVariant var = this->getJsonValueAsVariant(v, aliasName);
			quint64 foreignID = stringToNum<quint64>(var.toString().toStdString());
			if (foreignID < 1 || m_table.findByID64(foreignID) != nullptr)
			{
				this->addRecord(v);
			}
			else
			{
				m_needAddedList.insert(primaryId, v);
			}
		}
	}

	m_tableChanged = true;
}

void SyncTableBase::beginSyncFullTable()
{
	m_needAddedList.clear();
	m_needRemoveList.clear();
	for (int i = 0; i< m_table.recordCount(); ++i)
	{
		m_needRemoveList.insert(m_table[i].id64());
	}
	m_tableChanged = false;
}

void SyncTableBase::endSyncFullTable()
{
	if (m_tableChanged == false)
		return;

	for each (auto var in m_needRemoveList)
	{
		GSPRecord r = m_table.findByID64(var);
		if (r == nullptr)
			continue;
		m_table.remove(r);
	}

	if (m_toMineField.count() > 0)
	{
		size_t count = 0;
		std::string aliasName = m_toMineField.begin().value();
		while (m_needAddedList.count() > 0)
		{
			count = m_needAddedList.count();
			QMap<quint64, Json::Value>::iterator iter = m_needAddedList.begin();
			QMap<quint64, Json::Value>::iterator tempIter;
			for (; iter != m_needAddedList.end();)
			{
				tempIter = iter;
				++iter;
				quint64 foreignID = stringToNum<quint64>(tempIter.value()[aliasName].asString());
				if (m_table.findByID64(foreignID))
				{
					this->addRecord(tempIter.value());
					m_needAddedList.erase(tempIter);
				}
			}
			if (count == m_needAddedList.count())
			{
				THROWBMEXCEPTION(QStringLiteral("%1表，获取的全量数据，有部分数据添加不到数据库中"));
			}
		}
	}
}

