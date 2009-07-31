#include "manageTeachersWidget.h"
#include "ui_manageTeachersWidget.h"
#include "mainController.h"

ManageTeachersWidget::ManageTeachersWidget(MainController *mainController, QWidget *parent) :
		QWidget(parent),
		m_ui(new Ui::ManageTeachersWidget),
		m_mainController(mainController)

{
	m_ui->setupUi(this);

	m_teacherTableProxyModel.setSourceModel(m_mainController->teacherTableModel());
	m_ui->teachersTable->setModel(&m_teacherTableProxyModel);
}

ManageTeachersWidget::~ManageTeachersWidget()
{
	delete m_ui;
}
