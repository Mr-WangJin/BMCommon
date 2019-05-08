#include "stdafx.h"
#include "LogManager.h"
#include <QDateTime>
#include <QFile>
#include <QTextStream>

using namespace BMCOMMON;

#define Default_Log_File_Name "log.txt"

void outputMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
	QString logType;
	switch (type)
	{
	case QtDebugMsg:
		logType = QString("Debug    ");
		break;
	case QtWarningMsg:
		logType = QString("Warning  ");
		break;
	case QtCriticalMsg:
		logType = QString("Critical ");
		break;
	case QtFatalMsg:
		logType = QString("Fatal    ");
		break;
	case QtInfoMsg:

		break;
	default:break;
	}

	QString date_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm");
	QString file_info = QString("file:%1 line:%2").arg(QString(context.file)).arg(context.line);
	QString message = QString("{%1} {%2} {%3} {%4}")
		.arg(date_time).arg(logType).arg(file_info).arg(msg);

	LogManager::getInstance()->outputText(message);
}

BMCOMMON::LogManager::~LogManager()
{
	this->stopLog();
	delete m_logFile;
	m_logFile = nullptr;
}

LogManager * LogManager::getInstance()
{
	static LogManager m;

	return &m;
}

void LogManager::startLog()
{
	QMutexLocker locker(&m_mutex);
	m_isValid = true;
}

void LogManager::stopLog()
{
	QMutexLocker locker(&m_mutex);
	if (m_logFile && m_logFile->isOpen())
		m_logFile->close();
	m_isValid = false;
}

void BMCOMMON::LogManager::outputText(const QString & text)
{
	QMutexLocker locker(&m_mutex);
	if (m_isValid && m_logFile->isOpen())
	{
		QTextStream text_stream(m_logFile);
		text_stream << text << "\r\n";
		m_logFile->flush();
	}
}

bool BMCOMMON::LogManager::setLogFilePath(const QString & fileName)
{
	if (QFile::exists(fileName) == false)
		return false;

	QMutexLocker locker(&m_mutex);
	if (m_logFile && m_logFile->isOpen())
		m_logFile->close();
	
	m_logFile->setFileName(fileName);
	return m_logFile->open(QIODevice::WriteOnly | QIODevice::Append);
}

LogManager::LogManager()
{
	//×¢²áMessageHandler
	qInstallMessageHandler(outputMessage);

	m_isValid = false;
	m_logFile = new QFile(Default_Log_File_Name);
	m_logFile->open(QIODevice::WriteOnly | QIODevice::Append);
}
