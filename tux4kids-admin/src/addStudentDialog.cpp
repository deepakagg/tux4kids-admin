#include "addStudentDialog.h"
#include "ui_addStudentDialog.h"

#include <QListWidgetItem>
#include <QDebug>

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

	setInvalid();

	connect(m_ui->addButton, SIGNAL(clicked()), this, SLOT(addClicked()));
	connect(m_ui->firstNameEdit, SIGNAL(textEdited(QString)), this, SLOT(validate()));
	connect(m_ui->lastNameEdit, SIGNAL(textEdited(QString)), this, SLOT(validate()));

}

AddStudentDialog::~AddStudentDialog()
{
	delete m_ui;
}

QString AddStudentDialog::firstName() const
{
	return m_ui->firstNameEdit->text().simplified();
}

QString AddStudentDialog::lastName() const
{
	return m_ui->lastNameEdit->text().simplified();
}

void AddStudentDialog::addClicked()
{
	emit accepted();
	m_ui->firstNameEdit->clear();
	m_ui->lastNameEdit->clear();
}

QStringList AddStudentDialog::checkedApplicationNames() const
{
	QStringList result;
	foreach (QListWidgetItem *listItem, m_ui->applicationList->findItems(QString(), Qt::MatchContains)) {
		if (listItem->checkState() == Qt::Checked) {
			result.append(listItem->text());
		}
	}
	return result;
}

void AddStudentDialog::setApplicationNames(QStringList applicationNames)
{
	m_ui->applicationList->clear();

	foreach(QString name, applicationNames) {
		QListWidgetItem *listWidgetItem = new QListWidgetItem(name, m_ui->applicationList);
		listWidgetItem->setFlags(listWidgetItem->flags() | Qt::ItemIsUserCheckable);
		listWidgetItem->setCheckState(Qt::Unchecked);
	}
}

void AddStudentDialog::validate()
{
	if (m_ui->firstNameEdit->text().simplified().isEmpty()
		|| m_ui->lastNameEdit->text().simplified().isEmpty()) {
		setInvalid();
		return;
	}

	setValid();
}

void AddStudentDialog::setValid()
{
	m_ui->addButton->setEnabled(true);
}

void AddStudentDialog::setInvalid()
{
	m_ui->addButton->setEnabled(false);
}

