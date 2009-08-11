#ifndef EDITTUXMATHOPTIONS_H
a#define EDITTUXMATHOPTIONS_H

#include <QtGui/QDialog>

		namespace Ui {
	class EditTuxmathOptions;
}

class EditTuxmathOptions : public QDialog {
	Q_OBJECT
public:
	EditTuxmathOptions(QWidget *parent = 0);
	~EditTuxmathOptions();

private:
	Ui::EditTuxmathOptions *m_ui;
};

#endif // EDITTUXMATHOPTIONS_H
