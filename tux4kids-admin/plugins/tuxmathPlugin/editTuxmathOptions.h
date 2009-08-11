#ifndef EDITTUXMATHOPTIONS_H
#define EDITTUXMATHOPTIONS_H

#include <QtGui/QDialog>

namespace Ui {
	class EditTuxmathOptions;
}

class EditTuxmathOptions : public QDialog
{
	Q_OBJECT
public:
	EditTuxmathOptions(QWidget *parent = 0);
	~EditTuxmathOptions();

	bool allowAddition() const;
	bool allowSubstraction() const;

private:
	Ui::EditTuxmathOptions *m_ui;
};

#endif // EDITTUXMATHOPTIONS_H
