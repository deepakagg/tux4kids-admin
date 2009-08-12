#include "editWordListDialog.h"
#include "ui_editWordListDialog.h"

#include <QPushButton>

EditWordListDialog::EditWordListDialog(QWidget *parent)
		: QDialog(parent),
		m_ui(new Ui::EditWordListDialog)
{
	m_ui->setupUi(this);

	validate();

	connect(m_ui->nameEdit, SIGNAL(textEdited(QString)),
		this, SLOT(validate()));
	connect(m_ui->wordListEdit, SIGNAL(textChanged()),
		this, SLOT(validate()));
	connect(m_ui->buttonBox->button(QDialogButtonBox::Ok), SIGNAL(clicked()),
		this, SLOT(accept()));
	connect(m_ui->buttonBox->button(QDialogButtonBox::Cancel), SIGNAL(clicked()),
		this, SLOT(reject()));
}

EditWordListDialog::~EditWordListDialog()
{
	delete m_ui;
}

bool EditWordListDialog::isValid()
{
	if (m_ui->nameEdit->text().isEmpty()
		|| m_ui->wordListEdit->toPlainText().isEmpty()) {
		return false;
	}

	return true;
}

void EditWordListDialog::validate()
{
	if (isValid()) {
		m_ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
	} else {
		m_ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
	}
}

