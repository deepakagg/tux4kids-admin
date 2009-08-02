#ifndef EDITTEACHERDIALOG_H
#define EDITTEACHERDIALOG_H

#include <QtGui/QDialog>

namespace Ui {
	class EditTeacherDialog;
}

class EditTeacherDialog : public QDialog
{
	Q_OBJECT
public:
	EditTeacherDialog(QWidget *parent = 0);
	~EditTeacherDialog();

private:
	Ui::EditTeacherDialog *m_ui;

	bool isValid() const;

private slots:
	void validate();
};

#endif // EDITTEACHERDIALOG_H
