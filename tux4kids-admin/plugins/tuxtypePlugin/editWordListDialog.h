#ifndef EDITWORDLISTDIALOG_H
#define EDITWORDLISTDIALOG_H

#include <QtGui/QDialog>

namespace Ui {
	class EditWordListDialog;
}

class EditWordListDialog : public QDialog
{
	Q_OBJECT
public:
	EditWordListDialog(QWidget *parent = 0);
	~EditWordListDialog();

private:
	Ui::EditWordListDialog *m_ui;

	bool isValid();

private slots:
	void validate();

};

#endif // EDITWORDLISTDIALOG_H
