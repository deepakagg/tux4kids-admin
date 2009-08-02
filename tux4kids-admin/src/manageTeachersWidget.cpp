#include "manageTeachersWidget.h"
#include "ui_manageTeachersWidget.h"
#include "mainController.h"
#include "editTeacherDialog.h"

#include <QDebug>

ManageTeachersWidget::ManageTeachersWidget(MainController *mainController, QWidget *parent) :
		QWidget(parent),
		m_ui(new Ui::ManageTeachersWidget),
		m_mainController(mainController)

{
	m_ui->setupUi(this);

	m_teacherTableProxyModel.setSourceModel(m_mainController->teacherTableModel());
	m_ui->teachersTable->setModel(&m_teacherTableProxyModel);

	connect(m_ui->addTeacherButton, SIGNAL(clicked()), this, SLOT(addClicked()));
	connect(m_ui->editTeacherButton, SIGNAL(clicked()), this, SLOT(editClicked()));
	connect(m_ui->deleteTeacherButton, SIGNAL(clicked()), this, SLOT(deleteClicked()));
}

ManageTeachersWidget::~ManageTeachersWidget()
{
	delete m_ui;
}

void ManageTeachersWidget::addClicked()
{
	if (m_addTeacherDialog == 0) {
		m_addTeacherDialog = new EditTeacherDialog(this);
		connect(m_addTeacherDialog, SIGNAL(accepted()), this, SLOT(addAccepted()));
		connect(m_addTeacherDialog, SIGNAL(rejected()), this, SLOT(addRejected()));
	}
	m_addTeacherDialog->showNormal();
}

void ManageTeachersWidget::editClicked()
{
	if (m_editTeacherDialog == 0) {
		m_editTeacherDialog = new EditTeacherDialog(this);
		connect(m_editTeacherDialog, SIGNAL(accepted()), this, SLOT(editAccepted()));
		connect(m_editTeacherDialog, SIGNAL(rejected()), this, SLOT(editRejected()));
	}
	m_editTeacherDialog->showNormal();;
}

void ManageTeachersWidget::deleteClicked()
{

}

void ManageTeachersWidget::addAccepted()
{
	qDebug() << "add accepted";
}

void ManageTeachersWidget::addRejected()
{
	qDebug() << "add rejected";
}

void ManageTeachersWidget::editAccepted()
{
	qDebug() << "edit accepted";
}

void ManageTeachersWidget::editRejected()
{
	qDebug() << "edit rejected";
}

