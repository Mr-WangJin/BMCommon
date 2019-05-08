#pragma once

/** 
 *	同步表数据基类，针对不同表可派生不同的同步数据表类
 *	默认所有表使用该类同步数据
 *  同步的表只支持指向自己的外键数量为1个
 *	
 */

#include <QObject>
#include "json/value.h"
#include <QVector>
#include "BMGlobal.h"
#include "BMDefine.h"

namespace BIMCOMMON
{
	class TableVersion;
	class SyncProxyBase;
	class CascadeNode;

	struct FullNodeData
	{
		quint64 primaryId;
	}; 

	class BIMCOMMON_EXPORT SyncTableBase : public QObject
	{
	public:
		explicit SyncTableBase(SyncProxyBasePtr proxy, QObject *parent = 0);
		virtual ~SyncTableBase();

		void setTableName(const QString &tableName);
		const QString &getTableName() const;

		/** 
		 *	增量同步json数据，根据action状态调用add,remove,update
		 */
		virtual void syncTableRecord(const Json::Value &v);

		virtual void beginSyncTable();
		virtual void endSyncTable();

		/** 
		 *	同步全量json数据,每次同步不会全部清空表数据，
		 *	获取全部数据，对比数据，删除缺少的数据，更新已有数据
		 *  调用前需调用beginSyncFullTable，之后调用endSyncFullTable
		 */
		virtual void syncFullTableRecord(const Json::Value &v);

		virtual void beginSyncFullTable();
		virtual void endSyncFullTable();

		/** 
		 *	无用字段名配置,因为服务器端新建表时
		 *  可能会新建一些服务单使用的字段，PC端会忽略这些字段
		 */
		void addNoUsedFieldName(const QString &fieldName);
		void removeNoUsedFieldName(const QString &fieldName);
		
		virtual void initNoUsedFieldName() {};
		virtual void clearNoUsedFieldName();

		// 设置增量版本号
		void updateLocalRemoteVersion(const quint64 &version);
		// 设置本地全量表hash值
		void setLocalFullHashValue(const QString &hash);
		
		//全量更新时，如果获取的数据为空，则需要设置全量哈希值为false
		void setTableChanged(bool changed);

	protected:
		inline virtual void addRecord(const Json::Value &r);
		inline virtual void removeRecord(const Json::Value &r);
		//更新记录，如果没有找到相应记录，则返回false，否则返回true
		inline virtual void updateRecord(const Json::Value &r);

		//新增记录调用该函数，用于特殊处理
		virtual void afterAddedRecord(GSPRecord r) {};

		inline void setFieldValue(GSPField& field, const Json::Value &v);
		inline QVariant getJsonValueAsVariant(const Json::Value &v, const std::string & key);

		//获取Json::Value中的主键ID
		inline quint64 getValuePrimaryID(const Json::Value &r);
	private:
		/** 
		 *	初始化变量m_toMineField
		 */
		void initMineField();

	protected:
		SyncProxyBasePtr					m_syncProxy;			//同步工程信息
		QString								m_tableName;			//表名
		QString								m_primaryKey;

		GSPTable							m_table;
		GSPRecord							m_tableVersionR;

		//更新时，解决指向自己的外键不存在的问题
		QSet<quint64>						m_needRemoveList;
		QMap<quint64, Json::Value>			m_needAddedList;
		QMap<quint64, Json::Value>			m_needUpdateList;
		//当全量表hash值没有变时，获取的数据为空，则不用改变数据
		bool								m_tableChanged;

		QMap<QString,std::string>			m_toMineField;			//当前表中指向自己的<外键名，别名>

		QVector<QString>					m_noUsedFieldName;		//返回的数据中默认无用字段
	};



}
