#include "classTableProxyModel.h"
#include "classTableModel.h"

#include <QBitArray>

ClassTableProxyModel::ClassTableProxyModel(QObject *parent )
		: QSortFilterProxyModel(parent)
{
}

bool ClassTableProxyModel::lessThan(const QModelIndex &left, const QModelIndex &right) const
{
	if (left.column() == ClassTableModel::ClassSelected) {
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

bool ClassTableProxyModel::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const
{
	QModelIndex indexName = sourceModel()->index(sourceRow, ClassTableModel::ClassName, sourceParent);

	return sourceModel()->data(indexName).toString().contains(filterRegExp());

}

