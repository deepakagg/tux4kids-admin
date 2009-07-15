#include "studentTableProxyModel.h"
#include "studentDir.h"

StudentTableProxyModel::StudentTableProxyModel(QObject *parent)
		: QSortFilterProxyModel(parent)
{
}

bool StudentTableProxyModel::lessThan(const QModelIndex &left, const QModelIndex &right) const
{
	QVariant leftData = sourceModel()->data(left);
	QVariant rightData = sourceModel()->data(right);
	return QString::localeAwareCompare(leftData.toString(),
					   rightData.toString()) < 0;
}

