/*

This file is part of Tux4kids-admin Tuxtype plugin

Tux4kids-admin Tuxtype plugin is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or any later version.

Tux4kids-admin Tuxtype plugin is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Tux4kids-admin Tuxtype plugin.  If not, see <http://www.gnu.org/licenses/>.

Author: Michał Świtakowski <tux4kids at_here switakowski.com>, Copyright (C) 2009

*/

#include "tuxtypeMainWidget.h"
#include "ui_tuxtypeMainWidget.h"
#include "studentTableModel.h"
#include "selectStudentWidget.h"
#include "editWordListDialog.h"

TuxtypeMainWidget::TuxtypeMainWidget(SchoolData *schoolData, QWidget *parent) :
		QWidget(parent),
		m_ui(new Ui::TuxtypeMainWidget)
{
	m_ui->setupUi(this);

	m_studentTableModel.setSchoolData(schoolData);
	m_selectStudentWidget = new SelectStudentWidget(this);
	m_ui->verticalLayout->insertWidget(0, m_selectStudentWidget);
	m_selectStudentWidget->setStudentTableModel(&m_studentTableModel);

	connect(m_ui->setWordListButton, SIGNAL(clicked()), this, SLOT(setWordListClicked()));
}

TuxtypeMainWidget::~TuxtypeMainWidget()
{
	delete m_ui;
}

void TuxtypeMainWidget::setWordListClicked()
{
	EditWordListDialog editWordList;
	editWordList.exec();
}

