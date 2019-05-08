#pragma once

/**
 *  @description : �߳�������
 *  @author : wangjl
 *  @date : 2019/04/28
 */
#include "BMGlobal.h"
#include "AsyncTask/ThreadDef.h"
#include <QWaitCondition>
#include <QThread>

namespace BMCOMMON
{
	class WorkerThreadManager;

	class WorkerThread : public QThread
	{
	public:
		WorkerThread();
		virtual ~WorkerThread();

		void setWorkerThreadManager(WorkerThreadManager* workerManager);

		// ���������
		void addNewTask(ThreadTaskPtr task);

		// ��ֹ����
		void closeThread(void);
	protected:
		virtual void run();

	private:
		WorkerThreadManager * m_workerManager;

		QMutex m_taskMutex;
		QWaitCondition m_taskCond;
		ThreadTaskPtr m_task;
		bool m_close;

		int m_timeStamp;

	};

}

