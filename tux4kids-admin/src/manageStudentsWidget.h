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

#ifndef MANAGESTUDENTSWIDGET_H
#define MANAGESTUDENTSWIDGET_H

#include <QtGui/QWidget>
#include <QPointer>

#include "studentTableProxyModel.h"
//#include "mainController.h"

class AddStudentDialog;
class MainController;
class SelectStudentWidget;

namespace Ui {
	class ManageStudentsWidget;
}

class ManageStudentsWidget : public QWidget
{
	Q_OBJECT
public:
	ManageStudentsWidget(MainController *mainController, QWidget *parent = 0);
	~ManageStudentsWidget();

private:
	Ui::ManageStudentsWidget *m_ui;
	QPointer<AddStudentDialog> m_addStudentDialog;
	QPointer<MainController> m_mainController;
	QPointer<SelectStudentWidget> m_selectStudentWidget;

	void setEditButtonsEnabled(bool enable);

private slots:

	void addStudentClicked();
	void addStudent();
	void editStudentClicked();
	void deleteStudentClicked();
	void setEditButtons();
};

#endif // MANAGESTUDENTSWIDGET_H
