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

#ifndef SELECTTEACHERWIDGET_H
#define SELECTTEACHERWIDGET_H

#include <QtGui/QWidget>
#include <QTimer>

#include "teacherTableModel.h"
#include "teacherTableProxyModel.h"

namespace Ui {
	class SelectTeacherWidget;
}

class QTableView;

class SelectTeacherWidget : public QWidget
{
	Q_OBJECT
public:
	SelectTeacherWidget(QWidget *parent = 0);
	~SelectTeacherWidget();
	void setTeacherTableModel(TeacherTableModel *teacherTableModel);
	QTableView *teacherTable();
	QModelIndex selectedTeacherIndex();

private:
	Ui::SelectTeacherWidget *m_ui;

	TeacherTableProxyModel m_teacherTableProxyModel;
	QTimer m_searchTimer;

private slots:
	void searchEdited();
	void updateFilter();
};

#endif // SELECTTEACHERWIDGET_H
