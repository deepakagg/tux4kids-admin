#include "addStudentDialog.h"
#include "ui_addStudentDialog.h"

#include <QListWidgetItem>

AddStudentDialog::AddStudentDialog(QWidget *parent) :
		QDialog(parent),
		m_ui(new Ui::AddStudentDialog)
{
	m_ui->setupUi(this);

	QListWidgetItem *testListWidgetItem = new QListWidgetItem("tuxmath");
	testListWidgetItem->setFlags(testListWidgetItem->flags() | Qt::ItemIsUserCheckable);

	m_ui->applicationList->addItem(testListWidgetItem);

	testListWidgetItem->setCheckState(Qt::Unchecked);

	QListWidgetItem *testListWidgetItem2 = new QListWidgetItem("tuxtype");
	testListWidgetItem2->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);

	m_ui->applicationList->addItem(testListWidgetItem2);
	testListWidgetItem2->setCheckState(Qt::Unchecked);

}

AddStudentDialog::~AddStudentDialog()
{
	delete m_ui;
}

void AddStudentDialog::addClicked()
{
	emit accepted();
	m_ui->firstNameEdit->clear();
	m_ui->lastNameEdit->clear();
}
