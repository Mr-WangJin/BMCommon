#pragma once

/**
 *	RequestData����������,Ĭ�Ͽ�������ʱ3����������,Ĭ�ϳ�ʱʱ��40��
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
		*	��̬��������������
		*	�׳�std::exception�쳣
		*/
		void request(const QString& url, const QByteArray& sendData, RequestMethod requestmethod, QByteArray &rData);
		
		/** 
		 *	���ó�ʱ�����������
		 */
		void setTimeOutCount(const int &count);

		/** 
		 *	���ó�ʱʱ��
		 */
		void setTimeOut(int msec);
	protected:
		QString			m_token;
		size_t			m_timeOutCount;
		int				m_timeOutMsec;
	};
}

