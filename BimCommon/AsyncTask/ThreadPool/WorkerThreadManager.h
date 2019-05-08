#pragma once
/** 
 *	�����̹߳�����
 *	ͨ��m_busyThreads �� m_idleThreads���������̣߳�
 */

#include "BMGlobal.h"
#include "AsyncTask/ThreadDef.h"
#include <QWaitCondition>
#include <QThread>
#include <QObject>

namespace BMCOMMON
{

	class WorkerThreadManager : public QObject
	{
	public:
		WorkerThreadManager(int initThreadNum = -1);
		virtual ~WorkerThreadManager();

		//�ӿ��й����̳߳����ƶ�һ�������̵߳���æ�����̳߳��У�
		//���û�п��й����̣߳���һֱ�ȴ���
		WorkerThread*  getIdleWorkerThread();

		//�ӿ��й����̳߳����ƶ�һ�������̵߳���æ�����̳߳��У�
		//���û�п��й����̣߳����׳��쳣��
		WorkerThread*  tryGetIdleWorkerThread();

		//���ù����߳�Ϊ����
		void setWorkerThreadToIdle(WorkerThread* workThread);

		unsigned int getBusyWorkerCount();

		//��ֹ�����߳�
		void closeThread();

	private:
		QMutex m_mutex;
		QWaitCondition m_idleCondition;


		QVector<WorkerThread*> m_busyWorkerList;
		QVector<WorkerThread*> m_idleWorkerList;

		//��ʼ����ʱ�̳߳��е��̵߳ĸ���
		unsigned int m_initThreadNum;
// 		//������߳�����
// 		unsigned int m_maxThreadNum;
// 
// 		//�����̵߳���С���������������Ŀ���ڸ�ֵ���������ؿ��ܹ��أ���ʱ�б�Ҫ���ӿ����̳߳ص���Ŀ
// 		unsigned int m_idleThreadMinNum;
// 		//���е��̵߳������Ŀ, ���������Ŀ���ڸ�ֵ��������ǰ���ؿ��ܽ��ᣬ��ʱ��ɾ������Ŀ����߳�
// 		//ʵ�����������ǽ��̵߳���Ϊm_InitNum��
// 		unsigned int m_idleThreadMaxNum;
	};

}

