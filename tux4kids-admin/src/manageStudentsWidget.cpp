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

#include "manageStudentsWidget.h"
#include "ui_manageStudentsWidget.h"
#include "addStudentDialog.h"
#include "mainController.h"
#include "schoolData.h"
#include "studentDir.h"
#include "studentTableDelegate.h"
#include "selectStudentWidget.h"

#include <QDebug>
#include <QTableView>

ManageStudentsWidget::ManageStudentsWidget(MainController *mainController, QWidget *parent) :
		QWidget(parent),
		m_ui(new Ui::ManageStudentsWidget),
		m_addStudentDialog(0)
{
	m_ui->setupUi(this);
	m_mainController = mainController;

	m_selectStudentWidget = new SelectStudentWidget(this);
	m_ui->verticalLayout->insertWidget(0, m_selectStudentWidget);
	m_selectStudentWidget->studentTable()->
			setEditTriggers(QAbstractItemView::AllEditTriggers);

	m_selectStudentWidget->studentTable()
			->setItemDelegateForColumn(StudentTableModel::StudentComputer,
						      new StudentTableDelegate(this));

	m_selectStudentWidget->setStudentTableModel(m_mainController->studentTableModel());

	m_selectStudentWidget->studentTable()
			->hideColumn(StudentTableModel::StudentSelected);

	connect(m_ui->addStudentButton, SIGNAL(clicked()),
		this, SLOT(addStudentClicked()));
	connect(m_ui->editStudentButton, SIGNAL(clicked()),
		this, SLOT(editStudentClicked()));
	connect(m_ui->deleteStudentButton, SIGNAL(clicked()),
		this, SLOT(deleteStudentClicked()));
	connect(m_selectStudentWidget->studentTable()->selectionModel(),
		SIGNAL(selectionChanged(QItemSelection,QItemSelection)),
		this, SLOT(setEditButtons()));

	setEditButtons();
}

ManageStudentsWidget::~ManageStudentsWidget()
{
	delete m_ui;
	delete m_addStudentDialog;
}

void ManageStudentsWidget::addStudentClicked()
{
	if (m_addStudentDialog == 0) {
		m_addStudentDialog = new AddStudentDialog();
		m_addStudentDialog->setApplicationNames(m_mainController->pluginManager()->loadedPluginNames());
		connect(m_addStudentDialog, SIGNAL(accepted()), this, SLOT(addStudent()));
	}
	m_addStudentDialog->showNormal();
}

void ManageStudentsWidget::editStudentClicked()
{

}

void ManageStudentsWidget::deleteStudentClicked()
{

}

void ManageStudentsWidget::addStudent()
{
	StudentDir *studentDir = m_mainController->schoolData()->addStudent();
	studentDir->setFirstName(m_addStudentDialog->firstName());
	studentDir->setLastName(m_addStudentDialog->lastName());
	foreach (QString profileType, m_addStudentDialog->checkedApplicationNames()) {
		qDebug() << profileType;
		studentDir->addProfileDir(profileType);
	}
}

void ManageStudentsWidget::setEditButtons()
{
	if (m_selectStudentWidget->studentTable()
		->selectionModel()->selectedIndexes().isEmpty()) {

		setEditButtonsEnabled(false);
	} else {
		setEditButtonsEnabled(true);
	}
}

void ManageStudentsWidget::setEditButtonsEnabled(bool enable)
{
	m_ui->editStudentButton->setEnabled(enable);
	m_ui->deleteStudentButton->setEnabled(enable);
}


