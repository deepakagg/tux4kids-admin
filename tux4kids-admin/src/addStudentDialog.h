#ifndef ADDSTUDENTDIALOG_H
#define ADDSTUDENTDIALOG_H

#include <QtGui/QDialog>

namespace Ui {
	class AddStudentDialog;
}

class AddStudentDialog : public QDialog
{
	Q_OBJECT
public:
	AddStudentDialog(QWidget *parent = 0);
	~AddStudentDialog();

private:
	Ui::AddStudentDialog *m_ui;

private slots:
	void addClicked();

};

#endif // ADDSTUDENTDIALOG_H
