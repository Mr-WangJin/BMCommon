#pragma once
/** 
 *	ͬ����Ŀ��Ϣ��������ĿID��token��cloudServiceV1
 */

#include "BMGlobal.h"
#include <QObject>

namespace BIMCOMMON
{
	class BIMCOMMON_EXPORT SyncProjectInfo
	{
	public:
		SyncProjectInfo() {};
		SyncProjectInfo(const QString &projectID, const QString &token, const QString &cloudServiceV1);
		~SyncProjectInfo();

		const QString &getCloudServiceV1() const;
		void setCloudServiceV1(const QString &v1);

		const QString &getToken() const;
		void setToken(const QString &token);

		const QString & getProjectID() const;
		void setProjectID(const QString &projectID);

	private:
		QString m_token;
		QString m_projectID;
		QString m_cloudServiceV1;
	};
}

