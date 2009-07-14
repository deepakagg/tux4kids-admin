#include "manageStudentsWidget.h"
#include "ui_manageStudentsWidget.h"
#include "addStudentDialog.h"
#include "mainController.h"
#include "schoolData.h"
#include "studentDir.h"

ManageStudentsWidget::ManageStudentsWidget(MainController *mainController, QWidget *parent) :
		QWidget(parent),
		m_ui(new Ui::ManageStudentsWidget),
		m_addStudentDialog(0)
{
	m_ui->setupUi(this);

	m_mainController = mainController;
	connect(m_ui->addStudentButton, SIGNAL(clicked()), this, SLOT(addStudentClicked()));
}

ManageStudentsWidget::~ManageStudentsWidget()
{
	delete m_ui;
}

void ManageStudentsWidget::addStudentClicked()
{
	if (m_addStudentDialog == 0) {
		m_addStudentDialog = new AddStudentDialog();
		connect(m_addStudentDialog, SIGNAL(accepted()), this, SLOT(addStudent()));
	}
	m_addStudentDialog->showNormal();
}

void ManageStudentsWidget::addStudent()
{
	StudentDir *studentDir = m_mainController->schoolData()->addStudent();
	studentDir->setFirstName("John");
	studentDir->setLastName("Harry");
}

