#include "editTeacherDialog.h"
#include "ui_editTeacherDialog.h"
#include "selectClassWidget.h"

#include <QPushButton>

EditTeacherDialog::EditTeacherDialog(SchoolDatabase *schoolDatabase, QWidget *parent) :
		QDialog(parent),
		m_ui(new Ui::EditTeacherDialog),
		m_schoolDatabase(schoolDatabase)
{
	m_ui->setupUi(this);

	m_selectClassWidget = new SelectClassWidget();
	m_selectClassWidget->setClassTableModel(&m_classTableModel);
	m_ui->verticalLayout->insertWidget(1, m_selectClassWidget);

	m_classTableModel.setSchoolDatabase(m_schoolDatabase);

	connect(m_ui->firstNameEdit, SIGNAL(textEdited(QString)), this, SLOT(validate()));
	connect(m_ui->lastNameEdit, SIGNAL(textEdited(QString)), this, SLOT(validate()));
	connect(m_ui->buttonBox->button(QDialogButtonBox::Ok), SIGNAL(clicked()), this, SLOT(accept()));
	connect(m_ui->buttonBox->button(QDialogButtonBox::Cancel), SIGNAL(clicked()), this, SLOT(reject()));

	validate();
}

EditTeacherDialog::~EditTeacherDialog()
{
	delete m_ui;
}

bool EditTeacherDialog::isValid() const
{
	return (!m_ui->firstNameEdit->text().simplified().isEmpty() && !m_ui->lastNameEdit->text().simplified().isEmpty());
}

void EditTeacherDialog::validate()
{
	if (isValid()) {
		m_ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
	} else {
		m_ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
	}
}

Teacher EditTeacherDialog::teacher()
{
	editedTeacher.setFirstName(m_ui->firstNameEdit->text());
	editedTeacher.setLastName(m_ui->lastNameEdit->text());
	*editedTeacher.classes() = m_classTableModel.selectedClasses();
	return editedTeacher;
}

void EditTeacherDialog::setTeacher(Teacher &teacher)
{
	editedTeacher = teacher;
	m_ui->firstNameEdit->setText(editedTeacher.firstName());
	m_ui->lastNameEdit->setText(editedTeacher.lastName());
	m_classTableModel.setSelectedClasses(*editedTeacher.classes());

	validate();
}

void EditTeacherDialog::clear()
{
	m_ui->firstNameEdit->clear();
	m_ui->lastNameEdit->clear();
	m_classTableModel.clearSelection();

	validate();
}

