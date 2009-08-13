#include "manageStudentsWidget.h"
#include "ui_manageStudentsWidget.h"
#include "addStudentDialog.h"
#include "mainController.h"
#include "schoolData.h"
#include "studentDir.h"
#include "studentTableDelegate.h"

#include <QDebug>

ManageStudentsWidget::ManageStudentsWidget(MainController *mainController, QWidget *parent) :
		QWidget(parent),
		m_ui(new Ui::ManageStudentsWidget),
		m_addStudentDialog(0)
{
	m_ui->setupUi(this);

	m_ui->studentsTable->setEditTriggers(QAbstractItemView::SelectedClicked
					     | QAbstractItemView::EditKeyPressed);
	m_ui->studentsTable->setItemDelegateForColumn(StudentTableModel::StudentComputer,
						      new StudentTableDelegate(this));
	m_studentTableProxyModel.setSourceModel(mainController->studentTableModel());
	m_ui->studentsTable->setModel(&m_studentTableProxyModel);

	m_mainController = mainController;
	connect(m_ui->addStudentButton, SIGNAL(clicked()), this, SLOT(addStudentClicked()));
	connect(m_ui->editStudentButton, SIGNAL(clicked()), this, SLOT(editStudentClicked()));
	connect(m_ui->deleteStudentButton, SIGNAL(clicked()), this, SLOT(deleteStudentClicked()));
	connect(m_ui->studentsTable->selectionModel(), SIGNAL(selectionChanged(QItemSelection,QItemSelection)), this, SLOT(setEditButtons()));

	setEditButtons();
}

ManageStudentsWidget::~ManageStudentsWidget()
{
	delete m_ui;
	delete m_addStudentDialog;
}

void ManageStudentsWidget::addStudentClicked()
{
	if (m_addStudentDialog == 0) {
		m_addStudentDialog = new AddStudentDialog();
		m_addStudentDialog->setApplicationNames(m_mainController->pluginManager()->loadedPluginNames());
		connect(m_addStudentDialog, SIGNAL(accepted()), this, SLOT(addStudent()));
	}
	m_addStudentDialog->showNormal();
}

void ManageStudentsWidget::editStudentClicked()
{

}

void ManageStudentsWidget::deleteStudentClicked()
{

}

void ManageStudentsWidget::addStudent()
{
	StudentDir *studentDir = m_mainController->schoolData()->addStudent();
	studentDir->setFirstName(m_addStudentDialog->firstName());
	studentDir->setLastName(m_addStudentDialog->lastName());
	foreach (QString profileType, m_addStudentDialog->checkedApplicationNames()) {
		studentDir->addProfileDir(profileType);
	}
}

void ManageStudentsWidget::setEditButtons()
{
	if (m_ui->studentsTable->selectionModel()->selectedIndexes().isEmpty()) {
		setEditButtonsEnabled(false);
	} else {
		setEditButtonsEnabled(true);
	}
}

void ManageStudentsWidget::setEditButtonsEnabled(bool enable)
{
	m_ui->editStudentButton->setEnabled(enable);
	m_ui->deleteStudentButton->setEnabled(enable);
}


