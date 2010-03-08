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

#ifndef SELECTSTUDENTWIDGET_H
#define SELECTSTUDENTWIDGET_H

#include <QtGui/QWidget>
#include <QTimer>

#include "studentTableModel.h"
#include "studentTableProxyModel.h"

class QTableView;

namespace Ui {
	class SelectStudentWidget;
}

class SelectStudentWidget : public QWidget
{
	Q_OBJECT
public:
	SelectStudentWidget(QWidget *parent = 0);
	~SelectStudentWidget();

	void setStudentTableModel(StudentTableModel *studentTableModel);
	QTableView *studentTable();

private:
	Ui::SelectStudentWidget *m_ui;

	StudentTableModel m_studentTableModel;
	StudentTableProxyModel m_studentTableProxyModel;
	QTimer m_searchTimer;

private slots:
	void searchEdited();
	void updateFilter();
	void filterKeyColumnChanged(int index);

};

#endif // SELECTSTUDENTWIDGET_H
