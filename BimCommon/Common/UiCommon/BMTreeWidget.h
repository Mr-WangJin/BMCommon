#pragma once

/**
 *  @description : QTreeWidget����ع�������
 *  @author : wangjl
 *  @date : 2019/04/28
 */

#include "BMGlobal.h"

class QTreeWidgetItem;

namespace BMCOMMON
{
    class BIMCOMMON_EXPORT BMTreeWidget
    {
    public:

        /** 
         * ���ڵ�ѡ��״̬�仯�󣬼������ø���ѡ��״̬
         * @column : ѡ�������
         * @state  : ѡ�л��ѡ��״̬
         */
        static void itemCheckStateChanged(QTreeWidgetItem* item, const int &column, const Qt::CheckState &state);


    };



}