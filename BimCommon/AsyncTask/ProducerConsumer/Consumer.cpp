#include "stdafx.h"
#include "Consumer.h"
#include "AsyncParam.h"
#include "AsyncTask/BlockedQueue.h"
#include "AsyncTask.h"

BMCOMMON::Consumer::Consumer(AsyncBlockedQueuePtr consumerQueue, AsyncParamPtr param)
	: QThread()
	, m_consumerQueue(consumerQueue)
	, m_param(param)
{
	m_abort = false;
}

BMCOMMON::Consumer::~Consumer()
{
	this->stopProcess();
	this->wait();
}

void BMCOMMON::Consumer::run()
{
	while (1)
	{
		try
		{
			if (m_abort)
				return;

			AsyncTaskPtr task = m_consumerQueue->remove();
			task->runConsume();
		}
		catch (std::exception  &e)
		{
			QThread::msleep(10);
		}
	}
}

void BMCOMMON::Consumer::startProgress()
{
	QMutexLocker locker(&m_mutex);
	m_abort = false;
	this->start();
}

void BMCOMMON::Consumer::stopProcess()
{
	QMutexLocker locker(&m_mutex);
	m_abort = true;
}

