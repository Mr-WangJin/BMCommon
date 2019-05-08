/** 
 *	SyncProxyBase ����Ϊ����������࣬����ͬ��������ȫ�����ݡ���汾���ݡ�
 */
#pragma once

#include <QObject>
#include "BMGlobal.h"
#include "json/value.h"
#include "SyncProjectInfo.h"
#include "BMDefine.h"

namespace BIMCOMMON
{
	class SyncTableBase;

	class BIMCOMMON_EXPORT SyncProxyBase : public QObject
	{
		Q_OBJECT
	public:
		SyncProxyBase(const SyncProjectInfo & projectInfo);
		virtual ~SyncProxyBase();

		virtual void loadGSPModel(const QString & modelFileName);
		virtual GSPModel getModel();
		//virtual void setModel(GSPModel model);

		void setProjectInfo(const SyncProjectInfo & projectInfo);
		const SyncProjectInfo &getProjectInfo() const;

		QString getFullUrl(GSPRecord tableVersionR);

		virtual void saveModel();
		virtual GSPTable getTable(const QString &tableName, const QString &dbName = "DB");
		GSPTable getVersionTable(const QString &dbName = "DB");

		virtual void beginSyncTable();
		virtual void endSyncTable();
		virtual void rollback();
	protected:
		/**
		*	��֤���������Ƿ���������
		*	�׳�std::exception�쳣
		*/
		virtual bool isRemoteError(const Json::Value &v) { return false; };

	signals:
		void updatingTable(size_t page);

	protected:
		SyncProjectInfo m_projectInfo;

	private:
		GSPModel m_model;
		QString m_modelFileName;

	};


}


