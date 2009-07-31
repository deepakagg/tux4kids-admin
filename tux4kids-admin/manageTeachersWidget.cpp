#include "manageTeachersWidget.h"
#include "ui_manageTeachersWidget.h"

ManageTeachersWidget::ManageTeachersWidget(QWidget *parent) :
		QWidget(parent),
		m_ui(new Ui::ManageTeachersWidget)
{
	m_ui->setupUi(this);
}

ManageTeachersWidget::~ManageTeachersWidget()
{
	delete m_ui;
}
