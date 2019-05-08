#pragma once

#include "BMGlobal.h"
#include <QObject>
#include "BMDefine.h"
#include "AsyncTask/ThreadDef.h"

namespace BMCOMMON
{

	class Producer : public QThread
	{
	public:
		Producer(AsyncBlockedQueuePtr producerQueue, AsyncBlockedQueuePtr consumerQueue,
			AsyncParamPtr param);
		virtual ~Producer();

		virtual void startProgress();
		virtual void stopProcess();

	protected:
		virtual void run() override;

	private:
		AsyncParamPtr m_param;
		AsyncBlockedQueuePtr m_producerQueue;
		AsyncBlockedQueuePtr m_consumerQueue;

		bool m_abort;
		QMutex m_mutex;
	};
}

