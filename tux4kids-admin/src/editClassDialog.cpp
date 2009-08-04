#include "editClassDialog.h"
#include "ui_editClassDialog.h"
#include "selectStudentWidget.h"

#include <QPushButton>

EditClassDialog::EditClassDialog(QWidget *parent) :
		QDialog(parent),
		m_ui(new Ui::EditClassDialog)
{
	m_ui->setupUi(this);

	m_ui->verticalLayout->insertWidget(1, new SelectStudentWidget(this));

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

