#ifndef EDITCLASSDIALOG_H
#define EDITCLASSDIALOG_H

#include <QtGui/QDialog>

namespace Ui {
	class EditClassDialog;
}

class EditClassDialog : public QDialog
{
	Q_OBJECT
public:
	EditClassDialog(QWidget *parent = 0);
	~EditClassDialog();

private:
	Ui::EditClassDialog *m_ui;
};

#endif // EDITCLASSDIALOG_H
