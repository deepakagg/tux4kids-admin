/*

This file is part of Tux4kids-admin Tuxmath plugin

Tux4kids-admin Tuxmath plugin is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or any later version.

Tux4kids-admin Tuxmath plugin is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Tux4kids-admin Tuxmath plugin.  If not, see <http://www.gnu.org/licenses/>.

Author: Michał Świtakowski <tux4kids at_here switakowski.com>, Copyright (C) 2009

*/

#include "tuxmathMainWidget.h"
#include "ui_tuxmathMainWidget.h"

#include "schoolData.h"
#include "selectStudentWidget.h"
#include "editTuxmathOptions.h"
#include "profileDir.h"
#include "studentDir.h"
#include "profileDirTuxmath.h"
#include "tuxmathOptions.h"

#include <QDebug>

TuxmathMainWidget::TuxmathMainWidget(SchoolData *schoolData, QWidget *parent) :
		QWidget(parent),
		m_ui(new Ui::TuxmathMainWidget)
{
	m_ui->setupUi(this);


	m_studentTableModel.setSchoolData(schoolData);
	m_selectStudentWidget = new SelectStudentWidget(this);
	m_ui->verticalLayout->insertWidget(0, m_selectStudentWidget);
	m_selectStudentWidget->setStudentTableModel(&m_studentTableModel);

	connect(m_ui->setOptionsButton, SIGNAL(clicked()), this, SLOT(setOptionsClicked()));
}

TuxmathMainWidget::~TuxmathMainWidget()
{
	delete m_ui;
}

void TuxmathMainWidget::setOptionsClicked()
{
	EditTuxmathOptions editDialog;
	editDialog.exec();
	if (editDialog.result() == QDialog::Accepted) {
		QList<StudentDir *> students = m_studentTableModel.selectedStudents();
		foreach (StudentDir *student, students) {
			foreach (ProfileDir *profile, student->profiles()) {
				ProfileDirTuxmath *profileTm = qobject_cast<ProfileDirTuxmath *>(profile);
				if (profileTm != 0) {
					profileTm->tuxmathOptions()->setAdditionAllowed(editDialog.allowAddition());
					profileTm->tuxmathOptions()->setSubstractionAllowed(editDialog.allowSubstraction());
				}
			}
		}
	}
}

