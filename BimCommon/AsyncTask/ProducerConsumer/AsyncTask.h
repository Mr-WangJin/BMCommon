#pragma once

#include "BMGlobal.h"
#include "AsyncTask/AsyncTaskBase.h"
#include <QObject>

namespace BMCOMMON
{
	class BIMCOMMON_EXPORT AsyncTask : public AsyncTaskBase
	{
	public:
// 		enum TaskType
// 		{
// 			Only_Produce = 1,
// 			Only_Consume, 
// 			Produce_Consume
// 		};
	public:
		AsyncTask();
		virtual ~AsyncTask();

		AsyncTask(const AsyncTask &rht);

		virtual void runProduce() {};

		virtual void runConsume() {};

	};
}


