#include "editClassDialog.h"
#include "ui_editClassDialog.h"

EditClassDialog::EditClassDialog(QWidget *parent) :
		QDialog(parent),
		m_ui(new Ui::EditClassDialog)
{
	m_ui->setupUi(this);
}

EditClassDialog::~EditClassDialog()
{
	delete m_ui;
}
