#include "stdafx.h"
#include "BMGSPCommon.h"
#include "Int64Processor.h"
#include "GSPEngineUtils.h"
#include <GSPInterface.h>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

namespace BMCOMMON
{
	void LoadGSPModel(GSPModel & model, const QString & path, bool simpleDataIntf, bool readOnly)
	{
		model = gspEngine().createModel();
		try
		{
			GSPModelPersistent(model).loadFromFile(path, simpleDataIntf, readOnly);
		}
		catch (...)
		{
			model = NULL;
			model = gspEngine().createModel();
			model.setAttribute(akForceUseDom, true);
			GSPModelPersistent(model).loadFromFile(path, simpleDataIntf, readOnly);
		}
		Int64Processor::instance()->excute(model);//À©Õ¹64Î»
		model.setMode(gmRuntime);
	}

	void SaveGSPModel(GSPModel & model, const QString & fileName, bool compressData, bool encryptData)
	{
		GSPModelPersistent(model).saveToFile(fileName, compressData, encryptData);
	}

	void GetForeignToMineField(GSPTable table, QStringList & toMineList)
	{
		QString tableName = table.name();
		GSPFieldSchemas fields = table.tableSchema().fieldSchemas();
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
					toMineList.push_back(field.fieldName());
				}
			}
		}
	}

	void GetTableChildList(GSPTable table, QStringList& childList)
	{
		assert(table);

		GSPForeignKeyFieldSchemaList l = table.tableSchema().directDetailTableForeignKeys();
		for (int j = 0; j< l.count(); ++j)
		{
			childList.append(l.items(j).tableSchema().table().name());
		}
	}

	void ConvertGSPTableToJsonObject(GSPTable t, QJsonObject & obj, CONVER_GSPTABLE_TTYPE type)
	{
		auto funcLowercase = [](QString n) ->QString
		{
			if (n.isEmpty())
				return n;
			n[0] = n[0].toLower();
			return n;
		};

		auto funcGetAliasName = [&](GSPField f)->QString
		{
			QString fieldName = f.aliasName();
			if (fieldName.trimmed().isEmpty())
			{
				return funcLowercase(f.fieldName());
			}
			else
			{
				return fieldName.remove(0, 1);
			}
		};

		GSPTableSchema schema = t.tableSchema();

		QJsonArray arrayObj;
		for (int i = 0; i < t.recordCount(); ++i)
		{
			QJsonObject jsonObj;
			GSPRecord r = t[i];
			for (int j = 0; j < r.fieldCount(); ++j)
			{
				GSPField field = r.fields(j);
				QString fieldName;
				switch (type)
				{
				case BMCOMMON::FIELD_NAME:
					fieldName = field.fieldName();
					break;
				case BMCOMMON::ALIAS_NAME:
					fieldName = funcGetAliasName(field);
					break;
				case BMCOMMON::FIELD_NAME_FIRST_LOWERCASE:
					fieldName = funcLowercase(field.fieldName());
					break;
				default:
					break;
				}

				switch (field.fieldKind())
				{
				case fkPrimaryKey:
				case fkForeignKey:
					jsonObj[fieldName] = field.asString();
					continue;
					break;
				default:
					break;
				}

				switch (field.dataType())
				{
				case dtString:
				case dtText:
					jsonObj[fieldName] = field.asString();
					break;
				case dtBoolean:
					if (field.asBoolean())
						jsonObj[fieldName] = 1;
					else
						jsonObj[fieldName] = 0;
					break;
				case dtLongInt:
				case dtShortInt:
				case dtByte:
				case dtSmallInt:
					jsonObj[fieldName] = field.asInteger();
					break;
				case dtDouble:
				case dtDecimal:
					jsonObj[fieldName] = field.asFloat();
					break;
				case dtDateTime:
				{
					QDateTime dateTime = QDateTime::fromString(field.asString(), Qt::ISODate);;
					qint64 ms = dateTime.toMSecsSinceEpoch();
					jsonObj[fieldName] = ms;

				}
				break;
				case dtInt64:
					jsonObj[fieldName] = field.asInt64();
					break;
				case dtUInt64:
				case dtGUID:
					jsonObj[fieldName] = field.asString();
					break;
				default:
					break;
				}

			}
			arrayObj.insert(i, jsonObj);
		}

		QString tableName;
		switch (type)
		{
		case BMCOMMON::FIELD_NAME:
			tableName = t.name();
			break;
		case BMCOMMON::ALIAS_NAME:
			tableName = t.aliasName();
			if (tableName.isEmpty())
				tableName = funcLowercase(t.name());
			break;
		case BMCOMMON::FIELD_NAME_FIRST_LOWERCASE:
			tableName = funcLowercase(t.name());
			break;
		default:
			break;
		}
		obj[tableName] = arrayObj;

#ifdef _DEBUG

		QJsonDocument doc(obj);
		QString strJson(doc.toJson(QJsonDocument::Compact));

#endif // _DEBUG

	}

	//////////////////////////////////////////////////////////////////////////
	BMTableCopy::BMTableCopy(bool isCopyPrimaryID)
	{
		this->setIsCopyPrimaryID(isCopyPrimaryID);
	}

	BMTableCopy::~BMTableCopy()
	{

	}

	void BMTableCopy::setOriginPrimaryField(const QString & field)
	{
		m_OriginPrimaryField = field;
	}

	QMap<quint64, quint64> BMTableCopy::getPrimaryIdMaping()
	{
		return m_primaryIDMaping;
	}

	void BMTableCopy::clearPrimaryIDMaping()
	{
		m_primaryIDMaping.clear();
	}

	void BMTableCopy::setIsCopyPrimaryID(bool isCopyPrimaryID)
	{
		m_isCopyPrimaryID = isCopyPrimaryID;
	}

	GSPRecordList BMTableCopy::batchCloneTable(GSPTable fromTable, GSPTable toTable, const QStringList & unNormForeignFields, const QString & filter)
	{
		m_tempResult = gspEngine().createRecordList();
		m_unNormForeignFields = unNormForeignFields;

		GSPTableSchema fromTbSchema = fromTable.tableSchema();
		GSPTableSchema toTbSchema = toTable.tableSchema();

		std::vector<std::pair<int, int>> FromIdx_ToIdx;
		for (int i = 0; i < toTbSchema.fieldSchemas().count(); ++i)
		{
			QString fieldName = toTbSchema.fieldSchemas()[i].fieldName();
			GSPFieldSchema fieldSchema = fromTbSchema.findFieldSchema(fieldName);
			if (fieldSchema == nullptr)
				continue;
			if (fieldSchema.fieldKind() == fkPrimaryKey && !m_isCopyPrimaryID)
			{
				continue;
			}

			int fromIndex = fromTbSchema.findFieldSchema(fieldName).index();
			FromIdx_ToIdx.push_back(std::make_pair(fromIndex, i));
		}

		QString toMineForeignName;
		GSPForeignKeyFieldSchema foreignField = fromTbSchema.findForeignKey(fromTable.name());
		if (foreignField != nullptr)
			toMineForeignName = foreignField.fieldName();

		GSPRecordList iResults;
		if (toMineForeignName.isEmpty())
			iResults = fromTable.createRecordList(filter);
		else
		{
			if (filter.isEmpty())
				iResults = fromTable.createRecordList(QString("%1 = null").arg(toMineForeignName));
			else
				iResults = fromTable.createRecordList(QString("(%1 = null) and (%2)").arg(toMineForeignName).arg(filter));
		}

		for (int i = 0; i < iResults.count(); ++i)
		{
			CloneRecordToRecord(iResults[i], FromIdx_ToIdx, toMineForeignName, toTable);
		}

		return m_tempResult;
	}

	GSPRecord BMTableCopy::copyRecordToTable(GSPRecord fromR, GSPTable toTable, const bool &isCascadeDown)
	{
		m_tempResult = gspEngine().createRecordList();
		GSPTableSchema fromTbSchema = fromR.table().tableSchema();
		GSPTableSchema toTbSchema = toTable.tableSchema();

		std::vector<std::pair<int, int>> FromIdx_ToIdx;
		for (int i = 0; i < toTbSchema.fieldSchemas().count(); ++i)
		{
			QString fieldName = toTbSchema.fieldSchemas()[i].fieldName();
			GSPFieldSchema fieldSchema = fromTbSchema.findFieldSchema(fieldName);
			if (fieldSchema == nullptr)
				continue;
			if (fieldSchema.fieldKind() == fkPrimaryKey && !m_isCopyPrimaryID)
			{
				continue;
			}

			int fromIndex = fromTbSchema.findFieldSchema(fieldName).index();
			FromIdx_ToIdx.push_back(std::make_pair(fromIndex, i));
		}

		QString toMineForeignName;
		if (isCascadeDown)
		{
			GSPForeignKeyFieldSchema foreignField = fromTbSchema.findForeignKey(fromR.table().name());
			if (foreignField != nullptr)
				toMineForeignName = foreignField.fieldName();
		}

		CloneRecordToRecord(fromR, FromIdx_ToIdx, toMineForeignName, toTable);
		if (m_tempResult.count() > 0)
		{
			return m_tempResult[0];
		}
		return nullptr;
	}

	void BMTableCopy::CloneRecordToRecord(GSPRecord fromR, const std::vector<std::pair<int, int>> & FromIdx_ToIdx, QString toMineForeignName, GSPTable toTable)
	{
		GSPRecord newR = toTable.newRecord();
		for each (auto &var in FromIdx_ToIdx)
		{
			int secondFieldKind = newR.fields(var.second).fieldKind();
			int secondDataType = newR.fields(var.second).dataType();
			int firstFieldKind = fromR.fields(var.first).fieldKind();
			int firstDataType = fromR.fields(var.first).dataType();

			switch (secondDataType)
			{
			case dtString:
			{
				QString temp(fromR.fields(var.first).asString().data());
				newR.fields(var.second).setAsString(temp);
				continue;
			}
			break;
			default:
				break;
			}

			if (secondFieldKind == fkForeignKey || m_unNormForeignFields.contains(newR.fields(var.second).fieldName()))
			{
				quint64 foreignId = fromR.fields(var.first).asUInt64();
				if (!m_isCopyPrimaryID && m_primaryIDMaping.contains(foreignId))
				{
					newR.fields(var.second).setAsVariant(m_primaryIDMaping[foreignId]);
				}
				else
				{
					if (!toMineForeignName.isEmpty() && toTable.findByID64(fromR.asUInt64(toMineForeignName)) == nullptr)
						continue;
					GSPForeignKeyFieldSchema foreignFieldSchema = newR.fields(var.second).fieldSchema();
					if (foreignFieldSchema != nullptr)
					{
						QString masterTableName = foreignFieldSchema.masterTableSchema().primaryKey();
						QString filter = QString("%1 = %2").arg(masterTableName).arg(foreignId);
						GSPRecord fRecord = foreignFieldSchema.masterTableSchema().table().locateEx(filter);
						if (fRecord == nullptr)
							continue;
					}
					newR.fields(var.second).setAsVariant(fromR.fields(var.first).asVariant());
				}
				continue;
			}

			switch (secondFieldKind)
			{
			case fkNullExprData:
			{
				if (fromR.fields(var.first).dataIsNull())
					newR.fields(var.second).setDataIsNull(true);
				else
					newR.fields(var.second).setAsVariant(fromR.fields(var.first).asVariant());
			}
			break;
			case fkExpr:
			case fkCalc:
				break;
			default:
				newR.fields(var.second).setAsVariant(fromR.fields(var.first).asVariant());
				break;
			}
		}
		toTable.append(newR);
		m_tempResult.add(newR);

		if (!m_isCopyPrimaryID)
		{
			if (!m_OriginPrimaryField.isEmpty())
				newR.setAsUInt64(m_OriginPrimaryField, fromR.id64());
			m_primaryIDMaping.insert(fromR.id64(), newR.id64());
		}

		if (toMineForeignName.isEmpty())
			return;
		quint64 fromId = -1;
		if (fromR.fieldByName(toMineForeignName).dataType() == dtUInt64)
			fromId = fromR.id64();
		else
			fromId = fromR.id();
		GSPRecordList iResults = fromR.table().createRecordList(QString("%1 = %2").arg(toMineForeignName).arg(fromId));
		for (int i = 0; i < iResults.count(); ++i)
		{
			CloneRecordToRecord(iResults[i], FromIdx_ToIdx, toMineForeignName, toTable);
		}
	}
}