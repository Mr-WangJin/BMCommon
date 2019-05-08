#include "stdafx.h"
#include "LoginTool.h"
#include "SyncBim5d/RequestData.h"
#include "Exception/BMException.h"
#include "json/value.h"
#include "json/reader.h"

using namespace BIMCOMMON;


LoginTool::LoginTool(QObject* parent/* = nullptr*/)
	: QObject(parent)
{

}

LoginTool::~LoginTool()
{

}


UserInfoPtr LoginTool::Login(const QString &username, const QString & password, const QString &url)
{
	// 构造提交数据
	Json::Value requestData;
	requestData["username"] = username.toStdString();
	requestData["password"] = password.toStdString();
	requestData["clientType"] = "bim5d";
	requestData["machineId"] = "macAddress";

	QByteArray request_bytes = QByteArray::fromStdString(requestData.toStyledString());
	QByteArray return_bytes;
	RequestData request("");
	try
	{
		request.request(url, request_bytes, RequestData::rmPost, return_bytes);
		Json::Reader reader;
		Json::Value value;
		reader.parse(return_bytes.data(), value);

		if (value["code"].asInt() != 0 || value["message"].asString() != "success")
			THROWBMEXCEPTION(QStringLiteral("返回数据错误！"));
		Json::Value data = value["data"];

		UserInfoPtr userInof = UserInfoPtr(new UserInfo);

		userInof->cloudToken = QString::fromStdString(data["cloudToken"].asString());
		userInof->account = QString::fromStdString(data["account"].asString());
		userInof->userId = QString::fromStdString(data["userId"].asString());
		userInof->realName = QString::fromStdString(data["realName"].asString());
		userInof->mobile = QString::fromStdString(data["mobile"].asString());
		return userInof;
	}
	catch (std::exception &e)
	{
		THROWBMEXCEPTION(e.what());
	}
}


