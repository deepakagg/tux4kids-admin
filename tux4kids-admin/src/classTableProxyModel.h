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

#ifndef CLASSTABLEPROXYMODEL_H
#define CLASSTABLEPROXYMODEL_H

#include <QSortFilterProxyModel>

class ClassTableProxyModel : public QSortFilterProxyModel
{
	Q_OBJECT
public:
	ClassTableProxyModel(QObject *parent = 0);

	bool lessThan(const QModelIndex &left, const QModelIndex &right) const;
	bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const;
};

#endif // CLASSTABLEPROXYMODEL_H
