#pragma once

/**
 *	RequestData请求数据类,默认开启请求超时3次重新请求,默认超时时间40秒
 */

#include "BMGlobal.h"
#include "json/value.h"

class QNetworkAccessManager;

namespace BIMCOMMON
{
	class SyncProxyBase;

	class BIMCOMMON_EXPORT RequestData : public QObject
	{
		Q_OBJECT
	public:
		enum RequestMethod
		{
			rmGet,
			rmPost,
		};

	public:
		RequestData(QObject * parent = 0);
		RequestData(const QString & token, QObject * parent = 0);
		virtual ~RequestData();

		/**
		*	静态函数，请求数据
		*	抛出std::exception异常
		*/
		void request(const QString& url, const QByteArray& sendData, RequestMethod requestmethod, QByteArray &rData);
		
		/** 
		 *	设置超时重新请求次数
		 */
		void setTimeOutCount(const int &count);

		/** 
		 *	设置超时时间
		 */
		void setTimeOut(int msec);
	protected:
		QString			m_token;
		size_t			m_timeOutCount;
		int				m_timeOutMsec;
	};
}

