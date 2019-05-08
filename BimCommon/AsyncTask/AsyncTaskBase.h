#pragma once

/** 
 *  @description : 同步任务基类
 *  @author : wangjl
 *  @date : 2019/04/28
 */

#include "BMGlobal.h"
#include <QObject>

namespace BMCOMMON
{
	class BIMCOMMON_EXPORT AsyncTaskBase : public QObject
	{
	public:
		AsyncTaskBase();
		virtual ~AsyncTaskBase();

		void setTaskID(const quint64 &id) { m_taskID = id; };
		quint64 getTaskID() { return m_taskID; };

		void setTaskName(const QString &taskName) { m_taskName = taskName; };
		const QString &getTaskName() { return m_taskName; };

	private:
		quint64 m_taskID;
		QString m_taskName;

	};
}


