#include "manageTeachersWidget.h"
#include "ui_manageTeachersWidget.h"
#include "mainController.h"

ManageTeachersWidget::ManageTeachersWidget(MainController *mainController, QWidget *parent) :
		QWidget(parent),
		m_ui(new Ui::ManageTeachersWidget),
		m_mainController(mainController)

{
	m_ui->setupUi(this);

	m_ui->teachersTable->setModel(m_mainController->teacherTableModel());
}

ManageTeachersWidget::~ManageTeachersWidget()
{
	delete m_ui;
}
