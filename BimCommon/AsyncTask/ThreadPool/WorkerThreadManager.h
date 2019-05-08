#pragma once
/** 
 *	工作线程管理类
 *	通过m_busyThreads 和 m_idleThreads来管理工作线程，
 */

#include "BMGlobal.h"
#include "AsyncTask/ThreadDef.h"
#include <QWaitCondition>
#include <QThread>
#include <QObject>

namespace BMCOMMON
{

	class WorkerThreadManager : public QObject
	{
	public:
		WorkerThreadManager(int initThreadNum = -1);
		virtual ~WorkerThreadManager();

		//从空闲工作线程池中移动一个工作线程到繁忙工作线程池中，
		//如果没有空闲工作线程，则一直等待。
		WorkerThread*  getIdleWorkerThread();

		//从空闲工作线程池中移动一个工作线程到繁忙工作线程池中，
		//如果没有空闲工作线程，则抛出异常。
		WorkerThread*  tryGetIdleWorkerThread();

		//设置工作线程为空闲
		void setWorkerThreadToIdle(WorkerThread* workThread);

		unsigned int getBusyWorkerCount();

		//终止工作线程
		void closeThread();

	private:
		QMutex m_mutex;
		QWaitCondition m_idleCondition;


		QVector<WorkerThread*> m_busyWorkerList;
		QVector<WorkerThread*> m_idleWorkerList;

		//初始创建时线程池中的线程的个数
		unsigned int m_initThreadNum;
// 		//最大工作线程数量
// 		unsigned int m_maxThreadNum;
// 
// 		//空闲线程的最小数量，如果空闲数目低于该值，表明负载可能过重，此时有必要增加空闲线程池的数目
// 		unsigned int m_idleThreadMinNum;
// 		//空闲的线程的最大数目, 如果空闲数目高于该值，表明当前负载可能较轻，此时将删除多余的空闲线程
// 		//实现中我们总是将线程调整为m_InitNum个
// 		unsigned int m_idleThreadMaxNum;
	};

}

