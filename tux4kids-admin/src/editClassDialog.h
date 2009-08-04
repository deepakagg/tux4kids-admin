#ifndef EDITCLASSDIALOG_H
#define EDITCLASSDIALOG_H

#include <QtGui/QDialog>

#include "studentTableModel.h"


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

	bool isValid() const;

private slots:
	void validate();

};

#endif // EDITCLASSDIALOG_H

