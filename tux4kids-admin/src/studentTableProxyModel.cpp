#include "studentTableProxyModel.h"
#include "studentTableModel.h"
#include "studentDir.h"
#include "class.h"

#include <QList>

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

bool StudentTableProxyModel::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const
{
	StudentTableModel *tableModel =
			qobject_cast<StudentTableModel *>(sourceModel());
	if (tableModel == 0) {
		return true;
	}
	StudentDir *student = tableModel->studentAt(sourceRow);

	if (filterKeyColumn() == Everything) {
		foreach (Class c, *student->classes()) {
			if (c.name().contains(filterRegExp())) {
				return true;
			}
		}
		return student->firstName().contains(filterRegExp())
			|| student->lastName().contains(filterRegExp());
	} else if (filterKeyColumn() == FirstName) {
		return student->firstName().contains(filterRegExp());
	} else if (filterKeyColumn() == LastName) {
		return student->lastName().contains(filterRegExp());
	} else if (filterKeyColumn() == ClassName) {
		foreach (Class c, *student->classes()) {
			if (c.name().contains(filterRegExp())) {
				return true;
			}
		}
		return false;
	}

}

