#include "stdafx.h"
#include "WorkerThreadManager.h"
#include "WorkerThread.h"

using namespace BMCOMMON;

BMCOMMON::WorkerThreadManager::WorkerThreadManager(int initThreadNum/* = -1*/)
{
	 if (initThreadNum <= 0)
		 m_initThreadNum = QThread::idealThreadCount() + 2;
	else
		m_initThreadNum = initThreadNum;

	m_busyWorkerList.clear();
	m_idleWorkerList.clear();

	for (int i = 0; i < m_initThreadNum; ++i)
	{
		WorkerThread*  workThread = new WorkerThread;
		workThread->setWorkerThreadManager(this);
		m_idleWorkerList.push_back(workThread);
		workThread->start();
	}
}

BMCOMMON::WorkerThreadManager::~WorkerThreadManager()
{
	this->closeThread();
	QMutexLocker locker(&m_mutex);
	for each (auto var in m_idleWorkerList)
	{
		delete var;
	}
	for each (auto var in m_busyWorkerList)
	{
		delete var;
	}
	m_idleWorkerList.clear();
	m_busyWorkerList.clear();
}

WorkerThread* BMCOMMON::WorkerThreadManager::getIdleWorkerThread()
{
	//从空闲工作线程池中移动一个工作线程到繁忙工作线程池中，并返回
	QMutexLocker locker(&m_mutex);
	while (m_idleWorkerList.isEmpty())
		m_idleCondition.wait(&m_mutex);

	WorkerThread* idleWorker = m_idleWorkerList.front();
	m_idleWorkerList.pop_front();
	m_busyWorkerList.append(idleWorker);

	return idleWorker;
}

WorkerThread*  BMCOMMON::WorkerThreadManager::tryGetIdleWorkerThread()
{
	//从空闲工作线程池中移动一个工作线程到繁忙工作线程池中，并返回
	QMutexLocker locker(&m_mutex);
	if (m_idleWorkerList.isEmpty())
		throw std::exception("no idle work thread!");

	WorkerThread*  idleWorker = m_idleWorkerList.front();
	m_idleWorkerList.pop_front();
	m_busyWorkerList.append(idleWorker);

	return idleWorker;
}

void BMCOMMON::WorkerThreadManager::setWorkerThreadToIdle(WorkerThread* workThread)
{
	//从繁忙工作线程池中移动一个工作线程到空闲工作线程池中
	QMutexLocker locker(&m_mutex);

	m_busyWorkerList.removeOne(workThread);
	m_idleWorkerList.append(workThread);

	m_idleCondition.wakeAll();
}

unsigned int BMCOMMON::WorkerThreadManager::getBusyWorkerCount()
{
	QMutexLocker locker(&m_mutex);
	return m_busyWorkerList.size();
}

void BMCOMMON::WorkerThreadManager::closeThread()
{
	QMutexLocker locker(&m_mutex);
	
	for each (auto var in m_idleWorkerList)
	{
		var->closeThread();
	}
	for each (auto var in m_busyWorkerList)
	{
		var->closeThread();
	}
}

