#include "stdafx.h"
#include "Producer.h"
#include "AsyncParam.h"
#include "AsyncTask/BlockedQueue.h"
#include "AsyncTask.h"

BMCOMMON::Producer::Producer(AsyncBlockedQueuePtr producerQueue, AsyncBlockedQueuePtr consumerQueue,
	AsyncParamPtr param)
	: QThread()
{
	m_producerQueue = producerQueue;
	m_consumerQueue = consumerQueue;
	m_param = param;

	m_abort = false;
}

BMCOMMON::Producer::~Producer()
{
	this->stopProcess();
	this->wait();
}

void BMCOMMON::Producer::run()
{
	while (1)
	{
		try
		{
			if (m_abort)
				return;

			AsyncTaskPtr task = m_producerQueue->remove();
			task->runProduce();

			m_consumerQueue->put(task);
		}
		catch (std::exception &e)
		{
			QThread::msleep(10);
		}
	}
}

void BMCOMMON::Producer::startProgress()
{
	QMutexLocker locker(&m_mutex);
	m_abort = false;
	this->start();
}

void BMCOMMON::Producer::stopProcess()
{
	QMutexLocker locker(&m_mutex);
	m_abort = true;
}


