#pragma once

/** 
 *	输出Qt qDebug qInfo qWarning qCritical qFatal 消息到日志文件中
 *	默认为 log.txt, 需要定义宏 QT_MESSAGELOGCONTEXT
 *	如果需要禁用某些宏的时候，可以定义宏，例如禁用qDebug() 可以定义QT_NO_DEBUG_OUTPUT
 *	后期也可以新增相应的接口禁用qDebug、qInfo、qWarning等；
 **/


#include "BMGlobal.h"
#include <QMutex>

class QFile;

namespace BMCOMMON
{
	class BIMCOMMON_EXPORT LogManager
	{
	public:
		virtual ~LogManager();

		static LogManager* getInstance();

        void startLog();
        void stopLog();

		bool setLogFilePath(const QString &fileName);

		void outputText(const QString &text);
	protected:
		LogManager();
	private:

	private:
		bool		m_isValid;
		QFile*		m_logFile;
		QMutex		m_mutex;

	};
}
