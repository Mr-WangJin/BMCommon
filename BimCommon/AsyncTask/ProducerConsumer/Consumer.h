#pragma once

#include "BMGlobal.h"
#include <QObject>
#include "AsyncTask/ThreadDef.h"
#include "BMDefine.h"

namespace BMCOMMON
{
	class Consumer : public QThread
	{
	public:
		Consumer(AsyncBlockedQueuePtr consumerQueue, AsyncParamPtr param);
		virtual ~Consumer();

		virtual void startProgress();
		virtual void stopProcess();

	protected:
		virtual void run() override;


	private:
		AsyncBlockedQueuePtr m_consumerQueue;
		AsyncParamPtr m_param;

		bool m_abort;
		QMutex m_mutex;

	};
}

