#include "stdafx.h"
#include "ServiceConfig.h"
#include "GLDFileUtils.h"
#include "Exception/BMException.h"
#include "GEPInterface.h"

using namespace BIMCOMMON;

ServiceConfig::ServiceConfig(void)
{
	QString sFileName = exePath() + BimCommonXMLName;
	if (fileExists(sFileName))
	{
		try
		{
			m_doc = loadXMLDocument(sFileName);
			///m_doc.elementsByTagName("CloudService_v1")
			m_root = m_doc.documentElement();
#ifdef _DEBUG
			m_sCloudService_v1 = readStrFromXML(m_root, "CloudService_v1_debug");
			m_sCloudService_v3 = readStrFromXML(m_root, "CloudService_v3_debug");
#else
			m_sCloudService_v1 = readStrFromXML(m_root, "CloudService_v1");
			m_sCloudService_v3 = readStrFromXML(m_root, "CloudService_v3");
#endif // _DEBUG
		}
		catch (...)
		{
			THROWBMEXCEPTION("read BimCommonXML file error!");
		}
	} 
	else
	{
		THROWBMEXCEPTION(QString("could not find %1").arg(sFileName));
	}
}

ServiceConfig::~ServiceConfig(void)
{

}

// ServiceConfig* ServiceConfig::getInstance()
// {
// 	static ServiceConfig instance; //局部静态变量
// 	return &instance;
// }

QString ServiceConfig::getCloudService_v1()
{
	return m_sCloudService_v1;
}

QString ServiceConfig::getCloudService_v3()
{
	return m_sCloudService_v3;
}

