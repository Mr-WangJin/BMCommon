#include "stdafx.h"
#include "BimThread.h"

BMCOMMON::BimThread::BimThread()
    : QThread(nullptr)
    , m_objPtr(0)
    , m_nullParamFunc(nullptr)
    , m_objParamFunc(nullptr)
{
}

BMCOMMON::BimThread::~BimThread()
{
}

void BMCOMMON::BimThread::run()
{
    if (m_nullParamFunc)
    {
        m_nullParamFunc();
    }

    if (m_objParamFunc)
    {
        m_objParamFunc(m_objPtr);
    }
}




