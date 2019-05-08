#pragma once

#include "BMGlobal.h"
#include <QWaitCondition>

namespace BMCOMMON
{
	class AsyncParam
	{
	public:
		AsyncParam();
		virtual ~AsyncParam();

		QMutex m_mutex;

		QWaitCondition m_fullCondition;
		QWaitCondition m_emptyCondition;
	};
}


