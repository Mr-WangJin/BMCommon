#include "stdafx.h"
#include "BMTreeWidget.h"
#include <QTreeWidgetItem>


using namespace BMCOMMON;


void BMTreeWidget::itemCheckStateChanged(QTreeWidgetItem* item, const int &column, const Qt::CheckState &state)
{
    assert(item);
    assert(state == Qt::Checked || state == Qt::Unchecked);

    std::function<void(QTreeWidgetItem*, const Qt::CheckState &)> funcIterParentItem;
    funcIterParentItem = [&](QTreeWidgetItem* item, const Qt::CheckState & state)
    {
        if (item == nullptr)
            return;
        if (state == Qt::PartiallyChecked)
        {
            item->setCheckState(column, Qt::PartiallyChecked);
            funcIterParentItem(item->parent(), state);
        }
        else
        {
            Qt::CheckState state_ = state;
            if (item->childCount() > 0)
                state_ = item->child(0)->checkState(column);
            for (int i = 1; i< item->childCount(); ++i)
            {
                if (item->child(i)->checkState(column) != state_)
                {
                    state_ = Qt::PartiallyChecked;
                    break;
                }
            }
            item->setCheckState(column, state_);
            funcIterParentItem(item->parent(), state_);
        }
    };

    std::function<void(QTreeWidgetItem*, const Qt::CheckState &)> funcIterChildItem;
    funcIterChildItem = [&](QTreeWidgetItem* item, const Qt::CheckState & state)
    {
        item->setCheckState(column, state);
        
        for (int i = 0; i < item->childCount(); ++i)
        {
            funcIterChildItem(item->child(i), state);
        }
    };

    funcIterParentItem(item->parent(), item->checkState(column));
    funcIterParentItem(item, item->checkState(column));
}