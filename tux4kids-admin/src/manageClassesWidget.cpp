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

#include "manageClassesWidget.h"
#include "ui_manageClassesWidget.h"
#include "editClassDialog.h"
#include "mainController.h"
#include "schoolData.h"
#include "schoolDatabase.h"
#include "selectClassWidget.h"
#include "errorLog.h"

#include <QDebug>
#include <QTableView>

ManageClassesWidget::ManageClassesWidget(MainController *mainController, QWidget *parent) :
		QWidget(parent),
		m_ui(new Ui::ManageClassesWidget),
		m_mainController(mainController),
		m_schoolDatabase(mainController->schoolData()->schoolDatabase())
{
	m_ui->setupUi(this);

	m_selectClassWidget = new SelectClassWidget(this);
	m_ui->verticalLayout->insertWidget(0, m_selectClassWidget);
	m_selectClassWidget->setClassTableModel(m_mainController->classTableModel());
	m_selectClassWidget->classTable()->hideColumn(ClassTableModel::ClassSelected);

	connect(m_ui->addClassButton, SIGNAL(clicked()), this, SLOT(addClicked()));
	connect(m_ui->editClassButton, SIGNAL(clicked()), this, SLOT(editClicked()));
	connect(m_ui->deleteClassButton, SIGNAL(clicked()), this, SLOT(deleteClicked()));
	connect(m_selectClassWidget->classTable()->selectionModel(),
		SIGNAL(selectionChanged(QItemSelection,QItemSelection)),
		this, SLOT(setEditButtons()));

	setEditButtons();
}

ManageClassesWidget::~ManageClassesWidget()
{
	delete m_ui;
}

void ManageClassesWidget::addClicked()
{
	if (m_addClassDialog == 0) {
		m_addClassDialog = new EditClassDialog(m_mainController->schoolData(), this);
		connect(m_addClassDialog, SIGNAL(accepted()), this, SLOT(addAccepted()));
		connect(m_addClassDialog, SIGNAL(rejected()), this, SLOT(addRejected()));
	}
	if (m_addClassDialog->isHidden()) {
		m_addClassDialog->clear();
	}
	m_addClassDialog->showNormal();
}

void ManageClassesWidget::editClicked()
{
	if (m_editClassDialog == 0) {
		m_editClassDialog = new EditClassDialog(m_mainController->schoolData(), this);
		connect(m_editClassDialog, SIGNAL(accepted()), this, SLOT(editAccepted()));
		connect(m_editClassDialog, SIGNAL(rejected()), this, SLOT(editRejected()));
	}

	QModelIndex classIndex = m_selectClassWidget->selectedClassIndex();
	m_editClassDialog->setClass(m_mainController->classTableModel()->at(classIndex.row()));
	m_editClassDialog->showNormal();
}

void ManageClassesWidget::deleteClicked()
{
	QModelIndex classIndex = m_selectClassWidget->selectedClassIndex();
	m_schoolDatabase->deleteClass(m_mainController->classTableModel()->at(classIndex.row()));
	if (m_schoolDatabase->error()) {
		ErrorLog::log(m_schoolDatabase->lastError(), tr("Error occured during deleting class. \n %1").arg(m_schoolDatabase->lastError()));
	}
}

void ManageClassesWidget::addAccepted()
{
	Class newClass = m_addClassDialog->getClass();
	m_schoolDatabase->addClass(newClass);
	if (m_schoolDatabase->error()) {
		ErrorLog::log(m_schoolDatabase->lastError(), tr("Error occured during adding class. \n %1").arg(m_schoolDatabase->lastError()));
	}
}

void ManageClassesWidget::addRejected()
{
	qDebug() << "add rejected";
}

void ManageClassesWidget::editAccepted()
{
	Class editedClass = m_editClassDialog->getClass();
	m_schoolDatabase->updateClass(editedClass);
	if (m_schoolDatabase->error()) {
		ErrorLog::log(m_schoolDatabase->lastError(), tr("Error occured during editing class. \n %1").arg(m_schoolDatabase->lastError()));
	}
}

void ManageClassesWidget::editRejected()
{
	qDebug() << "edit rejected";
}

void ManageClassesWidget::setEditButtons()
{
	if (m_selectClassWidget->classTable()->selectionModel()
		->selectedIndexes().isEmpty()) {
		setEditButtonsEnabled(false);
	} else {
		setEditButtonsEnabled(true);
	}
}

void ManageClassesWidget::setEditButtonsEnabled(bool enable)
{
	m_ui->editClassButton->setEnabled(enable);
	m_ui->deleteClassButton->setEnabled(enable);
}

