#pragma once

/** 
 *	�첽��������࣬��װ�����ߡ������ߡ��������С����Ѷ���
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
		 *	�ȴ�����������ɣ���ɺ��߳̽����ٴ��ڼ���״̬
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
		
		size_t m_AllTaskCount;					//��¼��ӵ�������������
	};
}


