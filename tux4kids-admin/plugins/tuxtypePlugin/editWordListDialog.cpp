/*

This file is part of Tux4kids-admin Tuxtype plugin

Tux4kids-admin Tuxtype plugin is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or any later version.

Tux4kids-admin Tuxtype plugin is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Tux4kids-admin Tuxtype plugin.  If not, see <http://www.gnu.org/licenses/>.

Author: Michał Świtakowski <tux4kids at_here switakowski.com>, Copyright (C) 2009

*/

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

