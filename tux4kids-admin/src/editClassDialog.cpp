#include "editClassDialog.h"
#include "ui_editClassDialog.h"
#include "selectStudentWidget.h"
#include "selectTeacherWidget.h"
#include "schoolData.h"
#include "class.h"

#include <QPushButton>

EditClassDialog::EditClassDialog(SchoolData *schoolData, QWidget *parent) :
		QDialog(parent),
		m_ui(new Ui::EditClassDialog)
{
	m_ui->setupUi(this);

	m_schoolData = schoolData;

	m_selectStudentWidget = new SelectStudentWidget(this);
	m_selectStudentWidget->studentTableModel()->setSchoolData(m_schoolData);
	m_ui->verticalLayout->insertWidget(1, m_selectStudentWidget);

	m_selectTeacherWidget = new SelectTeacherWidget(this);
	m_selectTeacherWidget->teacherTableModel()->setSchoolDatabase(m_schoolData->schoolDatabase());
	m_ui->verticalLayout->insertWidget(2, m_selectTeacherWidget);

	connect(m_ui->nameEdit, SIGNAL(textEdited(QString)), this, SLOT(validate()));
	connect(m_ui->buttonBox->button(QDialogButtonBox::Ok), SIGNAL(clicked()), this, SLOT(accept()));
	connect(m_ui->buttonBox->button(QDialogButtonBox::Cancel), SIGNAL(clicked()), this, SLOT(reject()));

	validate();
}

EditClassDialog::~EditClassDialog()
{
	delete m_ui;
}

bool EditClassDialog::isValid() const
{
	return !m_ui->nameEdit->text().simplified().isEmpty();
}

void EditClassDialog::validate()
{
	if (isValid()) {
		m_ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
	} else {
		m_ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
	}
}

Class EditClassDialog::getClass() const
{
	Class result;

	result.setName(m_ui->nameEdit->text());
	*result.students() = m_selectStudentWidget->studentTableModel()->selectedStudentsDirNames();
	*result.teachers() = m_selectTeacherWidget->teacherTableModel()->selectedTeachers();

	return result;
}

void EditClassDialog::setClass(Class & newClass)
{
	m_ui->nameEdit->setText(newClass.name());
	m_selectTeacherWidget->teacherTableModel()->setSelectedTeachers(*newClass.teachers());
	m_selectStudentWidget->studentTableModel()->setSelectedStudents(*newClass.students());
}

