#pragma once

/** 
 *	ͬ�������ݻ��࣬��Բ�ͬ���������ͬ��ͬ�����ݱ���
 *	Ĭ�����б�ʹ�ø���ͬ������
 *  ͬ���ı�ֻ֧��ָ���Լ����������Ϊ1��
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
		 *	����ͬ��json���ݣ�����action״̬����add,remove,update
		 */
		virtual void syncTableRecord(const Json::Value &v);

		virtual void beginSyncTable();
		virtual void endSyncTable();

		/** 
		 *	ͬ��ȫ��json����,ÿ��ͬ������ȫ����ձ����ݣ�
		 *	��ȡȫ�����ݣ��Ա����ݣ�ɾ��ȱ�ٵ����ݣ�������������
		 *  ����ǰ�����beginSyncFullTable��֮�����endSyncFullTable
		 */
		virtual void syncFullTableRecord(const Json::Value &v);

		virtual void beginSyncFullTable();
		virtual void endSyncFullTable();

		/** 
		 *	�����ֶ�������,��Ϊ���������½���ʱ
		 *  ���ܻ��½�һЩ����ʹ�õ��ֶΣ�PC�˻������Щ�ֶ�
		 */
		void addNoUsedFieldName(const QString &fieldName);
		void removeNoUsedFieldName(const QString &fieldName);
		
		virtual void initNoUsedFieldName() {};
		virtual void clearNoUsedFieldName();

		// ���������汾��
		void updateLocalRemoteVersion(const quint64 &version);
		// ���ñ���ȫ����hashֵ
		void setLocalFullHashValue(const QString &hash);
		
		//ȫ������ʱ�������ȡ������Ϊ�գ�����Ҫ����ȫ����ϣֵΪfalse
		void setTableChanged(bool changed);

	protected:
		inline virtual void addRecord(const Json::Value &r);
		inline virtual void removeRecord(const Json::Value &r);
		//���¼�¼�����û���ҵ���Ӧ��¼���򷵻�false�����򷵻�true
		inline virtual void updateRecord(const Json::Value &r);

		//������¼���øú������������⴦��
		virtual void afterAddedRecord(GSPRecord r) {};

		inline void setFieldValue(GSPField& field, const Json::Value &v);
		inline QVariant getJsonValueAsVariant(const Json::Value &v, const std::string & key);

		//��ȡJson::Value�е�����ID
		inline quint64 getValuePrimaryID(const Json::Value &r);
	private:
		/** 
		 *	��ʼ������m_toMineField
		 */
		void initMineField();

	protected:
		SyncProxyBasePtr					m_syncProxy;			//ͬ��������Ϣ
		QString								m_tableName;			//����
		QString								m_primaryKey;

		GSPTable							m_table;
		GSPRecord							m_tableVersionR;

		//����ʱ�����ָ���Լ�����������ڵ�����
		QSet<quint64>						m_needRemoveList;
		QMap<quint64, Json::Value>			m_needAddedList;
		QMap<quint64, Json::Value>			m_needUpdateList;
		//��ȫ����hashֵû�б�ʱ����ȡ������Ϊ�գ����øı�����
		bool								m_tableChanged;

		QMap<QString,std::string>			m_toMineField;			//��ǰ����ָ���Լ���<�����������>

		QVector<QString>					m_noUsedFieldName;		//���ص�������Ĭ�������ֶ�
	};



}
