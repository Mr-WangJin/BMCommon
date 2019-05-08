#include "stdafx.h"
#include "WorkerThread.h"
#include "ThreadTask.h"
#include "WorkerThreadManager.h"


BMCOMMON::WorkerThread::WorkerThread()
{
	m_close = false;

	QDateTime time = QDateTime::currentDateTime();   //获取当前时间  
	m_timeStamp = time.toTime_t();   //将当前时间转为时间戳  
}

BMCOMMON::WorkerThread::~WorkerThread()
{
	this->closeThread();
	this->wait();
}

void BMCOMMON::WorkerThread::setWorkerThreadManager(WorkerThreadManager* workerManager)
{
	QMutexLocker locker(&m_taskMutex);
	m_workerManager = workerManager;
}

void BMCOMMON::WorkerThread::addNewTask(ThreadTaskPtr task)
{
	assert(nullptr != task && false == m_close);

	QMutexLocker locker(&m_taskMutex);
	m_task = task;
	//m_task->moveToThread(this);

	m_taskCond.wakeAll();
}

void BMCOMMON::WorkerThread::closeThread(void)
{
	m_close = true;

	QMutexLocker locker(&m_taskMutex);
	m_task = ThreadTaskPtr();

	m_taskCond.wakeAll();
}

void BMCOMMON::WorkerThread::run()
{
	for (;;)
	{
		if (m_close)
			break;

		m_taskMutex.lock();

		while (!m_task && !m_close)
		{
			m_taskCond.wait(&m_taskMutex);
		}

		if (nullptr == m_task)
		{
			m_taskMutex.unlock();
			continue;
		}

		m_task->run();
		m_task = ThreadTaskPtr();

		m_taskMutex.unlock();

		m_workerManager->setWorkerThreadToIdle(this);
	}
}




