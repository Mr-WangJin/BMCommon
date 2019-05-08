#pragma once

/** 
 *	异步请求管理类，包装生产者、消费者、生产队列、消费队列
 *	
 */

#include "BMDefine.h"
#include "AsyncTask/ThreadDef.h"
#include "AsyncTask/BlockedQueue.h"

namespace BMCOMMON
{
	class BIMCOMMON_EXPORT AsyncManager
	{
	public:
		AsyncManager(const size_t &producerCount = 1, const size_t &consumerCount = 1);
		virtual ~AsyncManager();

		void addTask(AsyncTaskPtr task);

		void startTask();
		void stopTask();

		/** 
		 *	等待所有任务完成，完成后，线程将不再处于激活状态
		 */
		bool waitFinishiTask();

	private:
		void initialize();

		AsyncBlockedQueuePtr getProducerQueue();

	private:
		QVector<ProducerPtr> m_producerVec;
		QVector<ConsumerPtr> m_consumerVec;

		AsyncBlockedQueuePtr m_producerQueue;
		AsyncBlockedQueuePtr m_consumerQueue;

		AsyncParamPtr m_param;

		size_t m_producerCount;
		size_t m_consumerCount;
		
		size_t m_AllTaskCount;					//记录添加的所有任务数量
	};
}


