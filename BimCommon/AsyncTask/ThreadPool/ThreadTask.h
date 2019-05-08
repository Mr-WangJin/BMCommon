#pragma once

/**
*  @description : 线程任务类
*  @author : wangjl
*  @date : 2019/04/28
*/

#include "BMGlobal.h"
#include "AsyncTask/AsyncTaskBase.h"

namespace BMCOMMON
{

	class BIMCOMMON_EXPORT ThreadTask : public AsyncTaskBase
	{
	public:
		ThreadTask();
		virtual ~ThreadTask();

		virtual void run() = 0;


	};

}

