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

