#include "stdafx.h"
#include "AsyncManager.h"
#include "Producer.h"
#include "Consumer.h"
#include "AsyncParam.h"
#include "AsyncTask.h"

using namespace BMCOMMON;


BMCOMMON::AsyncManager::AsyncManager(const size_t &producerCount, const size_t &consumerCount)
	: m_producerCount(producerCount)
	, m_consumerCount(consumerCount)
	, m_AllTaskCount(0)
{
	assert(m_producerCount > 0 && m_consumerCount > 0);
	this->initialize();
}

BMCOMMON::AsyncManager::~AsyncManager()
{
	this->stopTask();
}

void BMCOMMON::AsyncManager::addTask(AsyncTaskPtr task)
{
	m_producerQueue->put(task);
	++m_AllTaskCount;
}

AsyncBlockedQueuePtr BMCOMMON::AsyncManager::getProducerQueue()
{
	return m_producerQueue;
}

void BMCOMMON::AsyncManager::initialize()
{
	m_producerQueue = AsyncBlockedQueuePtr(new BlockedQueue<AsyncTaskPtr>(1));
	m_consumerQueue = AsyncBlockedQueuePtr(new BlockedQueue<AsyncTaskPtr>(1));

	m_param = AsyncParamPtr(new AsyncParam());

	for (size_t i = 0; i< m_producerCount; ++i)
	{
		auto var = ProducerPtr(new Producer(m_producerQueue, m_consumerQueue, m_param));
		m_producerVec.push_back(var);
	}

	for (size_t i = 0; i < m_consumerCount; ++i)
	{
		auto var = ConsumerPtr(new Consumer(m_consumerQueue, m_param));
		m_consumerVec.push_back(var);
	}
}

void BMCOMMON::AsyncManager::startTask()
{
	for each (auto var in m_producerVec)
	{
		var->startProgress();
	}

	for each (auto var in m_consumerVec)
	{
		var->startProgress();
	}
}


void BMCOMMON::AsyncManager::stopTask()
{
	for each (auto var in m_producerVec)
	{
		var->stopProcess();
	}

	for each (auto var in m_consumerVec)
	{
		var->stopProcess();
	}
}


bool BMCOMMON::AsyncManager::waitFinishiTask()
{
	//查看生产队列是否有值
	while (m_producerQueue->isEmpty() == false)
	{
		QThread::msleep(10);
	}
	for each (auto var in m_producerVec)
	{
		var->stopProcess();
		var->wait();
	}
	while (m_consumerQueue->isEmpty() == false)
	{
		QThread::msleep(10);
	}
	for each (auto var in m_consumerVec)
	{
		var->stopProcess();
		var->wait();
	}

	return true;
}



