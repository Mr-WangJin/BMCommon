#pragma once

/** 
 *	���Qt qDebug qInfo qWarning qCritical qFatal ��Ϣ����־�ļ���
 *	Ĭ��Ϊ log.txt, ��Ҫ����� QT_MESSAGELOGCONTEXT
 *	�����Ҫ����ĳЩ���ʱ�򣬿��Զ���꣬�������qDebug() ���Զ���QT_NO_DEBUG_OUTPUT
 *	����Ҳ����������Ӧ�Ľӿڽ���qDebug��qInfo��qWarning�ȣ�
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
