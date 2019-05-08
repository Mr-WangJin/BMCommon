#include "stdafx.h"
#include "RequestData.h"
#include <QEventLoop> 
#include "SyncProxyBase.h"
#include "Exception/BMException.h"
#include <QTimer>

using namespace BIMCOMMON;

RequestData::RequestData(QObject * parent/* = 0*/)
	: QObject(parent)
{
	this->setTimeOutCount(3);
}

RequestData::RequestData(const QString & token, QObject * parent)
	: QObject(parent)
	, m_token(token)
{
	this->setTimeOutCount(3);
}

RequestData::~RequestData()
{

}

void RequestData::request(const QString& url, const QByteArray& sendData, RequestMethod requestmethod, QByteArray &rData)
{
	m_timeOutCount--;
	QNetworkRequest request;
	request.setUrl(url);
	request.setUrl(QUrl(url));
	request.setRawHeader("Content-Type", "application/json");
	request.setRawHeader("endpoint", ("PC"));
	//request.setAttribute(QNetworkRequest::RedirectionTargetAttribute, true);
	if (!m_token.isEmpty())
		request.setRawHeader("Authorization", m_token.toLocal8Bit());

	QNetworkReply* reply = NULL;
	QNetworkAccessManager m_networkManager;
	if (requestmethod == rmGet)
		reply = m_networkManager.get(request);
	else
		reply = m_networkManager.post(request, sendData);
	reply->ignoreSslErrors();

	QEventLoop loop;
	connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
	//connect(&m_networkManager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
	
	loop.exec(QEventLoop::ExcludeUserInputEvents);

	{  
		// 处理响应
		int httpsCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
		if (QNetworkReply::NoError != reply->error())
		{
			QString errorMsg = QString("%1 : %2\nhttpsCode: %3").arg(reply->error()).arg(reply->errorString()).arg(httpsCode);
			THROWBMEXCEPTION(errorMsg);
		}
		rData = reply->readAll();
#ifdef _DEBUG
		QString a = rData.data();
#endif // _DEBUG
	}
// 	else {  // 处理超时
// 		disconnect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
// 		reply->abort();
// 		reply->deleteLater();
// 
// 		if (m_timeOutCount == 0)
// 		{
// 			THROWBMEXCEPTION(QStringLiteral("请求超时，%1").arg(url));
// 		}
// 		else
// 		{
// 			this->request(url, sendData, requestmethod, rData);
// 		}
// 	}
}

void RequestData::setTimeOutCount(const int &count)
{
	m_timeOutCount = count;
}

void RequestData::setTimeOut(int msec)
{
}


