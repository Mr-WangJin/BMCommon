#pragma once

#include "BMGlobal.h"
#include <iostream>  
#include <sstream>
#include <QSharedPointer>

namespace BMCOMMON
{

	enum SyncType
	{
		FullType = 1,				//全量
		IncrementType,				//增量
		FullTypeWidthHash,			//全量带有哈希值
	};

	enum ToRemoteFieldType
	{
		Alias_Type = 1,
		Customize_Type,
		FieldName_Type,
	};

	/* 全量同步类型 */
	enum FullSyncType
	{
		No_Hash = 1,
		With_Hash,
	};

	enum ActionType
	{
		Create_Type = 1,
		Update_Type,
		Delete_Type,
	};


	//模板函数：将string类型变量转换为常用的数值类型（此方法具有普遍适用性）  
	template <class T> 
	T stringToNum(const std::string& str)
	{
		std::istringstream iss(str);
		T num;
		iss >> num;
		return num;
	}

	class SyncCloudTProxy;
	typedef QSharedPointer<SyncCloudTProxy> SyncCloudTProxyPtr;
	//typedef const QSharedPointer<SyncCloudTProxy> SyncCloudTProxyConstPtr;

	class SyncProxyBase;
	typedef QSharedPointer<SyncProxyBase> SyncProxyBasePtr;

	class SyncTableBase;
	typedef QSharedPointer<SyncTableBase> SyncTableBasePtr;

	class SyncCloudTable;
	typedef QSharedPointer<SyncCloudTable> SyncCloudTablePtr;

	
}



