#include "stdafx.h"
#include "Int64Processor.h"
//#include "Int64Util.h"

using namespace BMCOMMON;

struct int64StrRelation
{
	int int64fieldIndex;
	int strFieldIndex;
};

Int64Processor::Int64Processor()
{
	
}

Int64Processor::~Int64Processor()
{

}

void Int64Processor::queryIDValue(GSPRecord & record, GVariant & idValue)
{
	//idValue = Int64Util::NewID();
}

void Int64Processor::setQueryIDValueFunc(GSPModel model)
{
	for (int i = 0; i < model.databaseCount(); i++)
	{
		GSPTables oTables = model.databases(i).tables();
		for (int j = 0; j < oTables.count(); j++)
		{
			GSPTable iTable = oTables.items(j);
			if(iTable.tableKind() == tkNormalTable)
			{
				GSPFieldSchema iFieldSchema = iTable.tableSchema().fieldSchemas().items(iTable.tableSchema().primaryKeyFieldIndex());
				GSPExtPropDef oPropDef = iFieldSchema.extPropDefs().find("DataType");
				if((iFieldSchema.dataType() == dtUInt64) || (NULL != oPropDef) && ("Int64" == oPropDef.value()))
					iTable.setOnQueryIDValue(this);
			}	
		} 
	}
}

void Int64Processor::excute(GSPModel model)
{
	if (model == NULL)
		return;

	//保证ID唯一,暂时协同版才需要单独赋ID，单机版自增长即可
	//if(!GBMClientConfig::getInstance()->dataProxyIsLocal())
		setQueryIDValueFunc(model);

	//先判断是否已经处理过Int64
	GSPExtPropDef oDef = model.extPropDefs().find("IgnoreProcessInt64");
	if((oDef != NULL) && (oDef.value() == "True"))
		return;

	model.setMode(gmDesign);
	for (int i = 0; i < model.databaseCount(); i++)
	{
		GSPTables oTables = model.databases(i).tables();
		for (int j = 0; j < oTables.count(); j++)
		{
			GSPTable iTable = oTables.items(j);
			GSPFieldSchemas schemas = iTable.tableSchema().fieldSchemas();
			for (int k = 0; k < schemas.count(); k++)
			{
				GSPFieldSchema oFieldSchema = schemas.items(k);
				GSPExtPropDef oPropDef = oFieldSchema.extPropDefs().find("DataType");
				if ((NULL != oPropDef) && ("Int64" == oPropDef.value()))
				{
					oFieldSchema.setDataType(dtUInt64);
				}
			}
		} 
	}
	 
//	if(!GBMClientConfig::getInstance()->dataProxyIsLocal())
// 	{
// 		QVector<int64StrRelation> oRelations;
// 		model.setMode(gmLoad);
// 
// 		for (int i = 0; i < model.databaseCount(); i++)
// 		{
// 			GSPTables oTables = model.databases(i).tables();
// 			for (int j = 0; j < oTables.count(); j++)
// 			{
// 				oRelations.clear();
// 				GSPTable iTable = oTables.items(j);
// 				GSPFieldSchemas schemas = iTable.tableSchema().fieldSchemas();
// 				for (int k = 0; k < schemas.count(); k++)
// 				{
// 					GSPFieldSchema oFieldSchema = schemas.items(k);
// 					if (oFieldSchema.dataType() == dtUInt64)
// 					{
// 						int strFieldIndex = schemas.indexOf(oFieldSchema.fieldName() + "_Int64Str");
// 						int64StrRelation oRelation;
// 						oRelation.int64fieldIndex = oFieldSchema.index();
// 						oRelation.strFieldIndex = strFieldIndex;
// 						oRelations.push_back(oRelation);
// 					}
// 				}
// 				if (oRelations.count() > 0)
// 				{
// 					for (int k = 0; k < iTable.recordCount(); k++)
// 					{
// 						GSPRecord iRecord = iTable.records(k);
// 						for (int n = 0; n < oRelations.count(); n++)
// 						{
// 							int64StrRelation oRelation = oRelations.at(n);
// 							GString s = iRecord.fields(oRelation.strFieldIndex).asString();
// 							if (s == "")
// 							{
// 								iRecord.fields(oRelation.int64fieldIndex).setIsNull(true);
// 							}
// 							else 
// 							{ 
// 								UINT64 ll = iRecord.fields(oRelation.strFieldIndex).asString().toULongLong();
// 								iRecord.fields(oRelation.int64fieldIndex).setAsUInt64(ll);
// 								iRecord.fields(oRelation.strFieldIndex).setIsNull(true);
// 							}
// 						}
// 					}
// 				}
// 			}
// 		}
// 	}

	//处理过则加一个标识
	oDef = model.extPropDefs().add();
	oDef.setCode("IgnoreProcessInt64");
	oDef.setValue("True");

	//打上当前版本号
// 	oDef = model.extPropDefs().add();
// 	oDef.setCode("ProductVersion");
// 	oDef.setValue(GBMClientConfig::getInstance()->version());
	model.setMode(gmRuntime);
}

Int64Processor *Int64Processor::instance()
{
	static Int64Processor instance;
	return &instance; 
}
