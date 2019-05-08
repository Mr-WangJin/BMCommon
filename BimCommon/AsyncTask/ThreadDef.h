#pragma once


#include <QSharedPointer>

namespace BMCOMMON
{

	//线程状态
	typedef enum _ThreadState
	{
		THREAD_RUNNING = 0x0,			//运行
		THREAD_IDLE = 0x1,				//空闲
		THREAD_EXIT = 0X2,				//退出
	}ThreadState;


	template<typename T>
	class BlockedQueue;
	class AsyncParam;
	class AsyncTask;

	typedef QSharedPointer<AsyncTask>						AsyncTaskPtr;
	typedef QSharedPointer<AsyncParam>						AsyncParamPtr;
	typedef QSharedPointer<BlockedQueue<AsyncTaskPtr>>		AsyncBlockedQueuePtr;

	class Producer;
	class Consumer;

	typedef QSharedPointer<Producer> ProducerPtr;
	typedef QSharedPointer<Consumer> ConsumerPtr;


	class ThreadTask;
	typedef QSharedPointer<ThreadTask> ThreadTaskPtr;

	typedef QSharedPointer<BlockedQueue<ThreadTaskPtr>>		ThreadTaskBlockedQueuePtr;

	class ThreadPool;
	typedef QSharedPointer<ThreadPool> ThreadPoolPtr;

	class WorkerThread;
	typedef QSharedPointer<WorkerThread> WorkerThreadPtr;

    class BimThread;
    typedef QSharedPointer<BimThread> BimThreadPtr;
    
	class WorkerThreadManager;
	typedef QSharedPointer<WorkerThreadManager> WorkerThreadManagerPtr;
}



