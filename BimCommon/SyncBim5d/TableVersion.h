#pragma once

/** 
 *	��汾�����࣬
 *  �¼�һ�ű�ķ�������TableVersion�����һ����¼��
 *	���ʹ���Զ����ֶΣ�����ToRemoteField�����Ӧ���ֶζ�Ӧ��¼
 *	����SyncTableType��ͬ����Ĭ�ϵ�SyncProxyBase
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
		 *	���ͬ������������ͬ������
		 */
		void addSyncTable(SyncTableBasePtr syncTable);

		/**
		 *	�ж�Model�Ƿ���Ҫ����
		 *	���øĺ���������ø��±�汾
		 */
		bool isNeedUpdate();

		/**
		 *	�ú���������ø��±�汾��
		 *  ���ݱ�������ȸ�����������ݣ��ٸ��µ�ǰ�����ݣ�֧������
		 *  �׳��쳣 BMException
		 *  @tableName	��GSP����
		 */
		void cascadeUpdateTable(const QString & tableName);

		/** 
		 *	����TableVersion�е����б�
		 *  ����ǰ��Ҫ���ø��°汾��
		 *  �׳��쳣 BMException
		 */
		void updateAllTable();

		SyncProxyBase* getSyncProxy() const { return m_syncProxy.data(); };

	signals:
		/** 
		 *	�ź����ڸ��±�����
		 */
		void beginSyncModel();
		void updatingTable(const QString &tableName, int percent);
		void endSyncModel();

	private:
		/**
		*	���±�汾��, ֧������
		*	�׳�BMException�쳣
		*/
		void updateTableVersion();

		/**
		 *	����ĳһ�ű����ݣ����ж��Ƿ��ڱ�汾������Ӧ��¼��������֧����������
		 *	�׳�std::exception�쳣
		 *  @tableName	��GSP����
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

