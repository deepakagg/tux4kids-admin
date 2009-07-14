#include "addStudentDialog.h"
#include "ui_addStudentDialog.h"

#include <QListWidgetItem>

AddStudentDialog::AddStudentDialog(QWidget *parent) :
		QDialog(parent),
		m_ui(new Ui::AddStudentDialog)
{
	m_ui->setupUi(this);

	QListWidgetItem *testListWidgetItem = new QListWidgetItem("haha");
	testListWidgetItem->setFlags(testListWidgetItem->flags() | Qt::ItemIsUserCheckable);

	m_ui->applicationList->addItem(testListWidgetItem);
	testListWidgetItem->setFlags(testListWidgetItem->flags() | Qt::ItemIsUserCheckable);
	testListWidgetItem->setCheckState(Qt::Unchecked);

	QListWidgetItem *testListWidgetItem2 = new QListWidgetItem("haha2");
	testListWidgetItem2->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);

	m_ui->applicationList->addItem(testListWidgetItem2);
	testListWidgetItem2->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
}

AddStudentDialog::~AddStudentDialog()
{
	delete m_ui;
}
