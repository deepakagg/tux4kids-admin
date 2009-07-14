#include "manageStudentsWidget.h"
#include "ui_manageStudentsWidget.h"
#include "addStudentDialog.h"

ManageStudentsWidget::ManageStudentsWidget(QWidget *parent) :
		QWidget(parent),
		m_ui(new Ui::ManageStudentsWidget),
		addStudentDialog(0)
{
	m_ui->setupUi(this);

	connect(m_ui->addStudentButton, SIGNAL(clicked()), this, SLOT(addStudentClicked()));
}

ManageStudentsWidget::~ManageStudentsWidget()
{
	delete m_ui;
}

void ManageStudentsWidget::addStudentClicked()
{
	if (addStudentDialog == 0) {
		addStudentDialog = new AddStudentDialog();
	}
	addStudentDialog->showNormal();
}
