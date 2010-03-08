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

#include "manageTeachersWidget.h"
#include "ui_manageTeachersWidget.h"
#include "mainController.h"
#include "editTeacherDialog.h"
#include "selectTeacherWidget.h"
#include "schoolData.h"
#include "errorLog.h"

#include <QDebug>
#include <QTableView>

ManageTeachersWidget::ManageTeachersWidget(MainController *mainController, QWidget *parent) :
		QWidget(parent),
		m_ui(new Ui::ManageTeachersWidget),
		m_mainController(mainController),
		m_schoolDatabase(mainController->schoolData()->schoolDatabase())

{
	m_ui->setupUi(this);

	m_selectTeacherWidget = new SelectTeacherWidget(this);
	m_ui->verticalLayout->insertWidget(0, m_selectTeacherWidget);
	m_selectTeacherWidget->setTeacherTableModel(m_mainController->teacherTableModel());
	m_selectTeacherWidget->teacherTable()->
			hideColumn(TeacherTableModel::TeacherSelected);

	connect(m_ui->addTeacherButton, SIGNAL(clicked()), this, SLOT(addClicked()));
	connect(m_ui->editTeacherButton, SIGNAL(clicked()), this, SLOT(editClicked()));
	connect(m_ui->deleteTeacherButton, SIGNAL(clicked()), this, SLOT(deleteClicked()));
	connect(m_selectTeacherWidget->teacherTable()->selectionModel(), SIGNAL(selectionChanged(QItemSelection,QItemSelection)), this, SLOT(setEditButtons()));

	setEditButtons();
}

ManageTeachersWidget::~ManageTeachersWidget()
{
	delete m_ui;
}

void ManageTeachersWidget::addClicked()
{
	if (m_addTeacherDialog == 0) {
		m_addTeacherDialog = new EditTeacherDialog(m_schoolDatabase, this);
		connect(m_addTeacherDialog, SIGNAL(accepted()), this, SLOT(addAccepted()));
		connect(m_addTeacherDialog, SIGNAL(rejected()), this, SLOT(addRejected()));
	}
	if (m_addTeacherDialog->isHidden()) {
		m_addTeacherDialog->clear();
	}
	m_addTeacherDialog->showNormal();
}

void ManageTeachersWidget::editClicked()
{
	if (m_editTeacherDialog == 0) {
		m_editTeacherDialog = new EditTeacherDialog(m_schoolDatabase, this);
		connect(m_editTeacherDialog, SIGNAL(accepted()), this, SLOT(editAccepted()));
		connect(m_editTeacherDialog, SIGNAL(rejected()), this, SLOT(editRejected()));
	}

	QModelIndex teacherIndex = m_selectTeacherWidget->selectedTeacherIndex();
	m_editTeacherDialog->setTeacher(m_mainController->teacherTableModel()->at(teacherIndex.row()));
	m_editTeacherDialog->showNormal();
}

void ManageTeachersWidget::deleteClicked()
{
	QModelIndex teacherIndex = m_selectTeacherWidget->selectedTeacherIndex();
	m_schoolDatabase->deleteTeacher(m_mainController->teacherTableModel()->at(teacherIndex.row()));
	if (m_schoolDatabase->error()) {
		ErrorLog::log(m_schoolDatabase->lastError(), tr("Error occured during deleting teacher. \n %1").arg(m_schoolDatabase->lastError()));
	}
}

void ManageTeachersWidget::addAccepted()
{
	Teacher addedTeacher = m_addTeacherDialog->teacher();
	m_schoolDatabase->addTeacher(addedTeacher);
	if (m_schoolDatabase->error()) {
		ErrorLog::log(m_schoolDatabase->lastError(), tr("Error occured during adding teacher. \n %1").arg(m_schoolDatabase->lastError()));
	}
}

void ManageTeachersWidget::addRejected()
{
	qDebug() << "add rejected";
}

void ManageTeachersWidget::editAccepted()
{
	Teacher updatedTeacher = m_editTeacherDialog->teacher();
	m_schoolDatabase->updateTeacher(updatedTeacher);
	if (m_schoolDatabase->error()) {
		ErrorLog::log(m_schoolDatabase->lastError(), tr("Error occured during editing teacher. \n %1").arg(m_schoolDatabase->lastError()));
	}
}

void ManageTeachersWidget::editRejected()
{
	qDebug() << "edit rejected";
}

void ManageTeachersWidget::setEditButtons()
{
	if (m_selectTeacherWidget->teacherTable()->selectionModel()->selectedIndexes().isEmpty()) {
		setEditButtonsEnabled(false);
	} else {
		setEditButtonsEnabled(true);
	}
}

void ManageTeachersWidget::setEditButtonsEnabled(bool enable)
{
	m_ui->editTeacherButton->setEnabled(enable);
	m_ui->deleteTeacherButton->setEnabled(enable);
}

