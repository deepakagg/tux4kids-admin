#include "manageClassesWidget.h"
#include "ui_manageClassesWidget.h"
#include "manageClassDialog.h"
#include "mainController.h"

ManageClassesWidget::ManageClassesWidget(MainController *mainController, QWidget *parent) :
		QWidget(parent),
		m_ui(new Ui::ManageClassesWidget),
		m_mainController(mainController)
{
	m_ui->setupUi(this);

	connect(m_ui->addClassButton, SIGNAL(clicked()), this, SLOT(addClicked()));
}

ManageClassesWidget::~ManageClassesWidget()
{
	delete m_ui;
}

void ManageClassesWidget::addClicked()
{
	if (m_addClassDialog == 0) {
		m_addClassDialog = new ManageClassDialog(m_mainController);
	}

	m_addClassDialog->showNormal();
}
