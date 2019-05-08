#pragma once

#include "BMGlobal.h"
#include <QSharedPointer>

namespace BIMCOMMON
{

	class BIMCOMMON_EXPORT UserInfo
	{
	public:
		QString cloudToken;
		QString userId;
		QString realName;
		QString mobile;
		QString account;
	};
	typedef QSharedPointer<UserInfo> UserInfoPtr;

	class BIMCOMMON_EXPORT LoginTool : public QObject
	{
		Q_OBJECT
	public:
		explicit LoginTool( QObject* parent = nullptr);
		virtual ~LoginTool();

		/** 
		 *	µÇÂ¼²Ù×÷
		 *	Å×³öBMExceptionÒì³£
		 */
		static UserInfoPtr Login(const QString &username, const QString &password, const QString &url);

	private:

	};

}