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

