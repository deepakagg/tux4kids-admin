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

#ifndef MANAGETEACHERSWIDGET_H
#define MANAGETEACHERSWIDGET_H

#include <QtGui/QWidget>
#include <QPointer>

#include "teacherTableProxyModel.h"

namespace Ui {
	class ManageTeachersWidget;
}

class MainController;
class EditTeacherDialog;
class SelectTeacherWidget;
class SchoolDatabase;

class ManageTeachersWidget : public QWidget
{
	Q_OBJECT
public:
	ManageTeachersWidget(MainController *mainController, QWidget *parent = 0);
	~ManageTeachersWidget();

private:
	Ui::ManageTeachersWidget *m_ui;
	QPointer<MainController> m_mainController;
	QPointer<EditTeacherDialog> m_addTeacherDialog;
	QPointer<EditTeacherDialog> m_editTeacherDialog;
	QPointer<SelectTeacherWidget> m_selectTeacherWidget;
	QPointer<SchoolDatabase> m_schoolDatabase;

	void setEditButtonsEnabled(bool enable);

private slots:
	void addClicked();
	void editClicked();
	void deleteClicked();
	void addAccepted();
	void addRejected();
	void editAccepted();
	void editRejected();
	void setEditButtons();

};

#endif // MANAGETEACHERSWIDGET_H
