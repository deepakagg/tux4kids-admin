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

#ifndef STUDENTTABLEDELEGATE_H
#define STUDENTTABLEDELEGATE_H

#include <QItemDelegate>

class StudentTableDelegate : public QItemDelegate
{
	Q_OBJECT
public:
	StudentTableDelegate(QObject *parent = 0);

	QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
			      const QModelIndex &index) const;
	void setEditorData(QWidget *editor, const QModelIndex &index) const;
	void setModelData(QWidget *editor, QAbstractItemModel *model,
			  const QModelIndex &index) const;
	void updateEditorGeometry(QWidget *editor,
				  const QStyleOptionViewItem &option, const
				  QModelIndex &index) const;
};

#endif // STUDENTTABLEDELEGATE_H
