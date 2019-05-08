#pragma once

#include "GLDXMLUtils.h"
#include "BMGlobal.h"

namespace BIMCOMMON
{
	#define BimCommonXMLName "BMData\\BimCommon.xml"

	class BIMCOMMON_EXPORT ServiceConfig
	{
	private:
		ServiceConfig(void);
		~ServiceConfig(void);;

	public:
		//static ServiceConfig *getInstance();
		
		QString getCloudService_v1();
		QString getCloudService_v3();

	private:
		GXMLDocument m_doc;

		GXMLNode m_root;

		QString m_sCloudService_v1;
		QString m_sCloudService_v3;

	};

}