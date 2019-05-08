#pragma once

/** 
 *	表版本管理类，
 *  新加一张表的方法，在TableVersion中添加一条记录，
 *	如果使用自定义字段，则在ToRemoteField添加相应的字段对应记录
 *	根据SyncTableType不同创建默认的SyncProxyBase
 */

#include <QObject>
#include "SyncTableBase.h"
#include <QMap>
#include <memory>

namespace Synchronization {
	class SyncServer;
}

namespace BIMCOMMON
{
	class SyncTableBase;
	class CloudServiceProxy;
	class SyncProxyBase;

	class BIMCOMMON_EXPORT TableVersion : public QObject
	{
		Q_OBJECT
	public:
		TableVersion(SyncProxyBasePtr syncProxy);
		~TableVersion();

		/** 
		 *	添加同步表，针对特殊表同步处理
		 */
		void addSyncTable(SyncTableBasePtr syncTable);

		/**
		 *	判断Model是否需要更新
		 *	调用改函数，会调用更新表版本
		 */
		bool isNeedUpdate();

		/**
		 *	该函数不会调用更新表版本号
		 *  根据表外键，先更新外键表数据，再更新当前表数据，支持事务
		 *  抛出异常 BMException
		 *  @tableName	：GSP表名
		 */
		void cascadeUpdateTable(const QString & tableName);

		/** 
		 *	更新TableVersion中的所有表
		 *  更新前需要调用更新版本号
		 *  抛出异常 BMException
		 */
		void updateAllTable();

		SyncProxyBase* getSyncProxy() const { return m_syncProxy.data(); };

	signals:
		/** 
		 *	信号正在更新表名称
		 */
		void beginSyncModel();
		void updatingTable(const QString &tableName, int percent);
		void endSyncModel();

	private:
		/**
		*	更新表版本号, 支持事务
		*	抛出BMException异常
		*/
		void updateTableVersion();

		/**
		 *	更新某一张表数据，会判断是否在表版本中有相应记录，函数不支持数据事务
		 *	抛出std::exception异常
		 *  @tableName	：GSP表名
		 */
		void updateTable(const QString & tableName);

	private:
		SyncCloudTablePtr m_syncTable;
		SyncProxyBasePtr m_syncProxy;
		QSharedPointer<Synchronization::SyncServer> m_syncServer;

		QMap<QString, SyncTableBasePtr> m_syncTableMap;

		bool m_updateAllTable;
		QVector<QString> m_alreadyUpdateTable;

		QString m_curUpdateTable;
		float m_percent;

	};

}

