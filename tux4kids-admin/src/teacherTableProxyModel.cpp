#include "teacherTableProxyModel.h"
#include "teacherTableModel.h"

TeacherTableProxyModel::TeacherTableProxyModel(QObject *parent)
		: QSortFilterProxyModel(parent)
{
}

bool TeacherTableProxyModel::lessThan(const QModelIndex &left, const QModelIndex &right) const
{
	if (left.column() ==TeacherTableModel::TeacherSelected) {
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

bool TeacherTableProxyModel::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const
{
	QModelIndex indexFirstName = sourceModel()->index(sourceRow, TeacherTableModel::TeacherFirstName, sourceParent);
	QModelIndex indexLastName = sourceModel()->index(sourceRow, TeacherTableModel::TeacherLastName, sourceParent);

	return sourceModel()->data(indexFirstName).toString().contains(filterRegExp())
			|| sourceModel()->data(indexLastName).toString().contains(filterRegExp());

}

