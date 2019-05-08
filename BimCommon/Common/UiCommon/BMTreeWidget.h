#pragma once

/**
 *  @description : QTreeWidget类相关公共函数
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
         * 树节点选择状态变化后，级联设置父子选择状态
         * @column : 选择项的列
         * @state  : 选中或非选中状态
         */
        static void itemCheckStateChanged(QTreeWidgetItem* item, const int &column, const Qt::CheckState &state);


    };



}