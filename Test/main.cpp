#include <QtWidgets/QApplication>
#include "Log/LogManager.h"
#include "AsyncTask/ThreadPool/WorkerThread.h"
#include "AsyncTask/BimThread.h"
#include <iostream>

using namespace BMCOMMON;

void print()
{
    std::cout << "print";
}

int main(int argc, char *argv[])
{

	QApplication a(argc, argv);

	BMCOMMON::LogManager::getInstance()->startLog();

    BimThreadPtr thread = BMCOMMON::BimThread::runFunc(print);
    thread->wait();

	qInfo("sdfasdfasdf");

	return 1;

}
