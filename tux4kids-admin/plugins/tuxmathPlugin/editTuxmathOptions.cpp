/*

This file is part of Tux4kids-admin Tuxmath plugin

Tux4kids-admin Tuxmath plugin is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or any later version.

Tux4kids-admin Tuxmath plugin is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Tux4kids-admin Tuxmath plugin.  If not, see <http://www.gnu.org/licenses/>.

Author: Michał Świtakowski <tux4kids at_here switakowski.com>, Copyright (C) 2009

*/

#include "editTuxmathOptions.h"
#include "ui_editTuxmathOptions.h"

#include <QPushButton>

EditTuxmathOptions::EditTuxmathOptions(QWidget *parent) :
		QDialog(parent),
		m_ui(new Ui::EditTuxmathOptions)
{
	m_ui->setupUi(this);

	connect(m_ui->buttonBox->button(QDialogButtonBox::Ok), SIGNAL(clicked()), this, SLOT(accept()));
	connect(m_ui->buttonBox->button(QDialogButtonBox::Cancel), SIGNAL(clicked()), this, SLOT(reject()));
}

EditTuxmathOptions::~EditTuxmathOptions()
{
	delete m_ui;
}

bool EditTuxmathOptions::allowAddition() const
{
	return m_ui->includeAddition->isChecked();
}

bool EditTuxmathOptions::allowSubstraction() const
{
	return m_ui->includeSubstraction->isChecked();
}

