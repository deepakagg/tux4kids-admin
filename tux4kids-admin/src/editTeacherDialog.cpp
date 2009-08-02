#include "editTeacherDialog.h"
#include "ui_editTeacherDialog.h"

#include <QPushButton>

EditTeacherDialog::EditTeacherDialog(QWidget *parent) :
		QDialog(parent),
		m_ui(new Ui::EditTeacherDialog)
{
	m_ui->setupUi(this);

	connect(m_ui->firstNameEdit, SIGNAL(textEdited(QString)), this, SLOT(validate()));
	connect(m_ui->lastNameEdit, SIGNAL(textEdited(QString)), this, SLOT(validate()));
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
		m_ui->buttonBox->button(QDialogButtonBox::Cancel)->setEnabled(true);
	} else {
		m_ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
		m_ui->buttonBox->button(QDialogButtonBox::Cancel)->setEnabled(false);
	}
}
