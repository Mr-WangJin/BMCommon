#pragma once

/**
 *  @description : �߳�������
 *  @author : wangjl
 *  @date : 2019/04/28
 */
#include "BMGlobal.h"
#include "AsyncTask/ThreadDef.h"
#include <QThread>

namespace BMCOMMON
{

    typedef void(*NullParamFunc)();
    typedef void(*ObjParamFunc)(quint64);

    class BIMCOMMON_EXPORT BimThread : public QThread
	{
	public:
        BimThread();
		virtual ~BimThread();

        /** 
         *  �½��߳�ִ���޲�������
         */
        static BimThreadPtr runFunc(NullParamFunc f)
        {
            BimThread* t = new BimThread();
            t->m_nullParamFunc = f;
            t->start();
            return BimThreadPtr(t);
        };

        /**
         *  �½��߳�ִ�е�����������
         *  @objPtr �� ������ĳ�������ָ��
         */
        static BimThreadPtr runFunc(ObjParamFunc f, quint64 objPtr)
        {
            BimThread* t = new BimThread();
            t->m_objParamFunc = f;
            t->m_objPtr = objPtr;
            t->start();
            return BimThreadPtr(t);
        };
        
	protected:
		virtual void run();

	private:
        NullParamFunc m_nullParamFunc;

        quint64 m_objPtr;
        ObjParamFunc m_objParamFunc;
	};

}

