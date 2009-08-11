#include "editTuxmathOptions.h"
#include "ui_editTuxmathOptions.h"

EditTuxmathOptions::EditTuxmathOptions(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::EditTuxmathOptions)
{
    m_ui->setupUi(this);
}

EditTuxmathOptions::~EditTuxmathOptions()
{
    delete m_ui;
}
