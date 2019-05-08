#include "stdafx.h"
#include "ThreadPool.h"
#include "WorkerThread.h"
#include "ThreadTask.h"
#include "WorkerThreadManager.h"

BMCOMMON::ThreadPool::ThreadPool(const int & initThreadNum/* = -1*/)
{
	m_closed = false;

	m_queue = ThreadTaskBlockedQueuePtr(new BlockedQueue<ThreadTaskPtr>());
	m_workerManager = WorkerThreadManagerPtr(new WorkerThreadManager(initThreadNum));
}

BMCOMMON::ThreadPool::~ThreadPool()
{
	this->closeThread();
	this->wait();
}

void BMCOMMON::ThreadPool::runThreadTask(ThreadTaskPtr task)
{
	assert(task);
	
	m_queue->put(task);
}

void BMCOMMON::ThreadPool::waitThread()
{
	for (;;)
	{
		if (m_queue->isEmpty() == false)
			continue;
		QMutexLocker locker(&m_mutex);
		unsigned int c = m_workerManager->getBusyWorkerCount();
		if (c > 0)
			continue;
		break;
	}
}

void BMCOMMON::ThreadPool::closeThread()
{
	m_closed = true;

	QMutexLocker locker(&m_mutex);

	m_workerManager->closeThread();
}

void BMCOMMON::ThreadPool::run()
{
	for (;;)
	{
		if (m_closed)
			break;

		m_mutex.lock();
		ThreadTaskPtr task;
		try
		{
			task = m_queue->remove();
		}
		catch (const std::exception& e)
		{
			m_mutex.unlock();
			continue;
		}

		WorkerThread* workThread = m_workerManager->getIdleWorkerThread();
		//workThread->moveToThread(workThread->thread());
		m_mutex.unlock();

		workThread->addNewTask(task);
	}


}


