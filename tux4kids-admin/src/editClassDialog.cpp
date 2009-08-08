#include "editClassDialog.h"
#include "ui_editClassDialog.h"
#include "selectStudentWidget.h"
#include "selectTeacherWidget.h"
#include "schoolData.h"
#include "class.h"

#include <QDebug>
#include <QPushButton>

EditClassDialog::EditClassDialog(SchoolData *schoolData, QWidget *parent) :
		QDialog(parent),
		m_ui(new Ui::EditClassDialog),
		m_schoolData(schoolData)
{
	m_ui->setupUi(this);

	m_studentTableModel.setSchoolData(m_schoolData);
	m_teacherTableModel.setSchoolDatabase(m_schoolData->schoolDatabase());

	m_selectStudentWidget = new SelectStudentWidget(this);
	m_selectStudentWidget->setStudentTableModel(&m_studentTableModel);
	m_ui->verticalLayout->insertWidget(1, m_selectStudentWidget);

	m_selectTeacherWidget = new SelectTeacherWidget(this);
	m_selectTeacherWidget->setTeacherTableModel(&m_teacherTableModel);
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

Class EditClassDialog::getClass()
{
	editedClass.setName(m_ui->nameEdit->text());
	*editedClass.students() = m_studentTableModel.selectedStudentsDirNames();
	*editedClass.teachers() = m_teacherTableModel.selectedTeachers();

	return editedClass;
}

void EditClassDialog::setClass(Class &newClass)
{
	editedClass = newClass;
	m_ui->nameEdit->setText(editedClass.name());
	m_teacherTableModel.setSelectedTeachers(*editedClass.teachers());
	m_studentTableModel.setSelectedStudents(*editedClass.students());
	validate();
}

void EditClassDialog::clear()
{
	m_ui->nameEdit->clear();
	m_teacherTableModel.clearSelection();
	m_studentTableModel.clearSelection();
	validate();
}

