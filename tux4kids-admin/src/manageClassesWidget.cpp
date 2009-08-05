#include "manageClassesWidget.h"
#include "ui_manageClassesWidget.h"
#include "editClassDialog.h"
#include "mainController.h"
#include "schoolData.h"
#include "schoolDatabase.h"

#include <QDebug>

ManageClassesWidget::ManageClassesWidget(MainController *mainController, QWidget *parent) :
		QWidget(parent),
		m_ui(new Ui::ManageClassesWidget),
		m_mainController(mainController),
		m_schoolDatabase(mainController->schoolData()->schoolDatabase())
{
	m_ui->setupUi(this);

	m_classTableProxyModel.setSourceModel(m_mainController->classTableModel());
	m_ui->classesTable->setModel(&m_classTableProxyModel);

	connect(m_ui->addClassButton, SIGNAL(clicked()), this, SLOT(addClicked()));
	connect(m_ui->editClassButton, SIGNAL(clicked()), this, SLOT(editClicked()));
	connect(m_ui->classesTable->selectionModel(), SIGNAL(selectionChanged(QItemSelection,QItemSelection)), this, SLOT(setEditButtons()));

	setEditButtons();
}

ManageClassesWidget::~ManageClassesWidget()
{
	delete m_ui;
}

void ManageClassesWidget::addClicked()
{
	if (m_addClassDialog == 0) {
		m_addClassDialog = new EditClassDialog(m_mainController->schoolData(), this);
		connect(m_addClassDialog, SIGNAL(accepted()), this, SLOT(addAccepted()));
		connect(m_addClassDialog, SIGNAL(rejected()), this, SLOT(addRejected()));
	}
	m_addClassDialog->showNormal();
}

void ManageClassesWidget::editClicked()
{
	if (m_editClassDialog == 0) {
		m_editClassDialog = new EditClassDialog(m_mainController->schoolData(), this);
		connect(m_editClassDialog, SIGNAL(accepted()), this, SLOT(editAccepted()));
		connect(m_editClassDialog, SIGNAL(rejected()), this, SLOT(editRejected()));
	}
	m_editClassDialog->showNormal();
}

void ManageClassesWidget::deleteClicked()
{

}

void ManageClassesWidget::addAccepted()
{
	qDebug() << "add accepted";
	Class newClass = m_addClassDialog->getClass();
	m_schoolDatabase->addClass(newClass);
	if (m_schoolDatabase->error()) {
		qDebug() << m_schoolDatabase->lastError();
	}
}

void ManageClassesWidget::addRejected()
{
	qDebug() << "add rejected";
}

void ManageClassesWidget::editAccepted()
{
	qDebug() << "edit accepted";
}

void ManageClassesWidget::editRejected()
{
	qDebug() << "edit rejected";
}

void ManageClassesWidget::setEditButtons()
{
	if (m_ui->classesTable->selectionModel()->selectedIndexes().isEmpty()) {
		setEditButtonsEnabled(false);
	} else {
		setEditButtonsEnabled(true);
	}
}

void ManageClassesWidget::setEditButtonsEnabled(bool enable)
{
	m_ui->editClassButton->setEnabled(enable);
	m_ui->deleteClassButton->setEnabled(enable);
}

