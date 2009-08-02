#include "editClassDialog.h"
#include "ui_editClassDialog.h"

#include <QPushButton>

EditClassDialog::EditClassDialog(QWidget *parent) :
		QDialog(parent),
		m_ui(new Ui::EditClassDialog)
{
	m_ui->setupUi(this);

	connect(m_ui->nameEdit, SIGNAL(textEdited(QString)), this, SLOT(validate()));
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
		m_ui->buttonBox->button(QDialogButtonBox::Cancel)->setEnabled(true);
	} else {
		m_ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
		m_ui->buttonBox->button(QDialogButtonBox::Cancel)->setEnabled(false);
	}
}

