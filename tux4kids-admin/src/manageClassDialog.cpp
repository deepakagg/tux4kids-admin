#include "manageClassDialog.h"
#include "ui_manageClassDialog.h"
#include "mainController.h"

ManageClassDialog::ManageClassDialog(MainController *mainController, QWidget *parent) :
		QDialog(parent),
		m_ui(new Ui::ManageClassDialog),
		m_mainController(mainController)
{
	m_ui->setupUi(this);

	m_studentTableModel.setSchoolData(m_mainController->schoolData());
	m_ui->studentsTable->setModel(&m_studentTableModel);
}

ManageClassDialog::~ManageClassDialog()
{
	delete m_ui;
}
