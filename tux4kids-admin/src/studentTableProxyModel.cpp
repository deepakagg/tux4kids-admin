/*

This file is part of Tux4kids-admin

Tux4kids-admin is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or any later version.

Tux4kids-admin is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Tux4kids-admin.  If not, see <http://www.gnu.org/licenses/>.

Author: Michał Świtakowski <tux4kids at_here switakowski.com>, Copyright (C) 2009

*/

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
		if (student->classes()->empty()) {
			return true;
		}
		foreach (Class c, *student->classes()) {
			if (c.name().contains(filterRegExp())) {
				return true;
			}
		}
		return false;
	}
	return true;
}

