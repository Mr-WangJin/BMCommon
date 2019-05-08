#pragma once

#include "BMGlobal.h"
#include <iostream>  
#include <sstream>
#include <QSharedPointer>

namespace BMCOMMON
{

	enum SyncType
	{
		FullType = 1,				//ȫ��
		IncrementType,				//����
		FullTypeWidthHash,			//ȫ�����й�ϣֵ
	};

	enum ToRemoteFieldType
	{
		Alias_Type = 1,
		Customize_Type,
		FieldName_Type,
	};

	/* ȫ��ͬ������ */
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


	//ģ�庯������string���ͱ���ת��Ϊ���õ���ֵ���ͣ��˷��������ձ������ԣ�  
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



