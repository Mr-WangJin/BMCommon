#include "stdafx.h"
#include "SyncProjectInfo.h"

using namespace BIMCOMMON;

SyncProjectInfo::SyncProjectInfo(const QString &projectID, const QString &token, const QString &cloudServiceV1)
	: m_cloudServiceV1(cloudServiceV1)
	, m_token(token)
	, m_projectID(projectID)
{

}

SyncProjectInfo::~SyncProjectInfo()
{

}

void SyncProjectInfo::setCloudServiceV1(const QString &v1)
{
	m_cloudServiceV1 = v1;
}

const QString & SyncProjectInfo::getCloudServiceV1() const
{
	return m_cloudServiceV1;
}

const QString &SyncProjectInfo::getToken() const
{
	return m_token;
}

void SyncProjectInfo::setToken(const QString & token)
{
	m_token = token;
}

const QString & SyncProjectInfo::getProjectID() const
{
	return m_projectID;
}

void SyncProjectInfo::setProjectID(const QString &projectID)
{
	m_projectID = projectID;
}


