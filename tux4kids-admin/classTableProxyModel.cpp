#include "classTableProxyModel.h"
#include "classTableModel.h"

ClassTableProxyModel::ClassTableProxyModel(QObject *parent )
		: QSortFilterProxyModel(parent)
{
}

bool ClassTableProxyModel::lessThan(const QModelIndex &left, const QModelIndex &right) const
{
	QVariant leftData = sourceModel()->data(left);
	QVariant rightData = sourceModel()->data(right);

	switch(left.column()) {
	case ClassTableModel::ClassSelected:
		if (leftData.toBool() && !rightData.toBool()) {
			return true;
		} else {
			return false;
		};
	case ClassTableModel::ClassName:
		return QString::localeAwareCompare(leftData.toString(),
					   rightData.toString()) < 0;
	}
}
