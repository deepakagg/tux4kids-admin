#include "studentTableProxyModel.h"
#include "studentTableModel.h"
#include "studentDir.h"

StudentTableProxyModel::StudentTableProxyModel(QObject *parent)
		: QSortFilterProxyModel(parent)
{
}

bool StudentTableProxyModel::lessThan(const QModelIndex &left, const QModelIndex &right) const
{
	if (left.column() == StudentTableModel::StudentSelected) {
		if ((sourceModel()->data(left, Qt::CheckStateRole).toInt() == Qt::Checked) && (sourceModel()->data(right, Qt::CheckStateRole).toInt() == Qt::Unchecked)) {
			return true;
		} else {
			return false;
		};
	} else {
		QVariant leftData = sourceModel()->data(left);
		QVariant rightData = sourceModel()->data(right);
		return QString::localeAwareCompare(leftData.toString(),
					   rightData.toString()) < 0;
	}
}

