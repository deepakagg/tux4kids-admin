#include "classTableProxyModel.h"
#include "classTableModel.h"

#include <QBitArray>

ClassTableProxyModel::ClassTableProxyModel(QObject *parent )
		: QSortFilterProxyModel(parent)
{
}

bool ClassTableProxyModel::lessThan(const QModelIndex &left, const QModelIndex &right) const
{
	switch(left.column()) {
	case ClassTableModel::ClassSelected:
		if ((sourceModel()->data(left, Qt::CheckStateRole).toInt() == Qt::Checked) && (sourceModel()->data(right, Qt::CheckStateRole).toInt() == Qt::Unchecked)) {
			return true;
		} else {
			return false;
		};
	case ClassTableModel::ClassName: {
		QVariant leftData = sourceModel()->data(left);
		QVariant rightData = sourceModel()->data(right);
		return QString::localeAwareCompare(leftData.toString(),
					   rightData.toString()) < 0;
		}
	}
	return false;
}
