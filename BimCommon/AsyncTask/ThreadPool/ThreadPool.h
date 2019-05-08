#pragma once


#include "BMGlobal.h"
#include "AsyncTask/ThreadDef.h"
#include "AsyncTask/BlockedQueue.h"
#include <QWaitCondition>

namespace BMCOMMON
{

	class BIMCOMMON_EXPORT ThreadPool : public QThread
	{
	public:
		ThreadPool(const int & initThreadNum = -1);
		~ThreadPool();

		void runThreadTask(ThreadTaskPtr task);

		/** 
		 *	等待所有线程任务完成，并不关闭任务线程
		 */
		void waitThread();

		//关闭所有线程任务
		void closeThread();

	protected:
		virtual void run();

	private:
		
	private:
		QMutex m_mutex;
		WorkerThreadManagerPtr		m_workerManager;
		ThreadTaskBlockedQueuePtr	m_queue;
		
		bool m_closed;
	};
}



