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

#include "editClassDialog.h"
#include "ui_editClassDialog.h"
#include "selectStudentWidget.h"
#include "selectTeacherWidget.h"
#include "schoolData.h"
#include "class.h"

#include <QDebug>
#include <QPushButton>

EditClassDialog::EditClassDialog(SchoolData *schoolData, QWidget *parent) :
		QDialog(parent),
		m_ui(new Ui::EditClassDialog),
		m_schoolData(schoolData)
{
	m_ui->setupUi(this);

	m_studentTableModel.setSchoolData(m_schoolData);
	m_teacherTableModel.setSchoolDatabase(m_schoolData->schoolDatabase());

	m_selectStudentWidget = new SelectStudentWidget(this);
	m_selectStudentWidget->setStudentTableModel(&m_studentTableModel);
	m_ui->verticalLayout->insertWidget(1, m_selectStudentWidget);

	m_selectTeacherWidget = new SelectTeacherWidget(this);
	m_selectTeacherWidget->setTeacherTableModel(&m_teacherTableModel);
	m_ui->verticalLayout->insertWidget(2, m_selectTeacherWidget);

	connect(m_ui->nameEdit, SIGNAL(textEdited(QString)), this, SLOT(validate()));
	connect(m_ui->buttonBox->button(QDialogButtonBox::Ok), SIGNAL(clicked()), this, SLOT(accept()));
	connect(m_ui->buttonBox->button(QDialogButtonBox::Cancel), SIGNAL(clicked()), this, SLOT(reject()));

	validate();
}

EditClassDialog::~EditClassDialog()
{
	delete m_ui;
}

bool EditClassDialog::isValid() const
{
	return !m_ui->nameEdit->text().simplified().isEmpty();
}

void EditClassDialog::validate()
{
	if (isValid()) {
		m_ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
	} else {
		m_ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
	}
}

Class EditClassDialog::getClass()
{
	editedClass.setName(m_ui->nameEdit->text());
	*editedClass.students() = m_studentTableModel.selectedStudentsDirNames();
	*editedClass.teachers() = m_teacherTableModel.selectedTeachers();

	return editedClass;
}

void EditClassDialog::setClass(Class &newClass)
{
	editedClass = newClass;
	m_ui->nameEdit->setText(editedClass.name());
	m_teacherTableModel.setSelectedTeachers(*editedClass.teachers());
	m_studentTableModel.setSelectedStudents(*editedClass.students());
	validate();
}

void EditClassDialog::clear()
{
	m_ui->nameEdit->clear();
	m_teacherTableModel.clearSelection();
	m_studentTableModel.clearSelection();
	validate();
}

