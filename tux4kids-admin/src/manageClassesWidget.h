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

#ifndef MANAGECLASSESWIDGET_H
#define MANAGECLASSESWIDGET_H

#include <QtGui/QWidget>
#include <QPointer>

#include "classTableProxyModel.h"

namespace Ui {
	class ManageClassesWidget;
}

class MainController;
class EditClassDialog;
class SchoolDatabase;
class SelectClassWidget;

class ManageClassesWidget : public QWidget
{
	Q_OBJECT
public:
	ManageClassesWidget(MainController *mainController, QWidget *parent = 0);
	~ManageClassesWidget();

private:
	Ui::ManageClassesWidget *m_ui;

	QPointer<MainController> m_mainController;
	QPointer<SchoolDatabase> m_schoolDatabase;
	QPointer<EditClassDialog> m_addClassDialog;
	QPointer<EditClassDialog> m_editClassDialog;
	QPointer<SelectClassWidget> m_selectClassWidget;

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

#endif // MANAGECLASSESWIDGET_H
