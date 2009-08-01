#include "editTeacherDialog.h"
#include "ui_editTeacherDialog.h"

EditTeacherDialog::EditTeacherDialog(QWidget *parent) :
		QDialog(parent),
		m_ui(new Ui::EditTeacherDialog)
{
	m_ui->setupUi(this);
}

EditTeacherDialog::~EditTeacherDialog()
{
	delete m_ui;
}
