#ifndef ADDSTUDENTDIALOG_H
#define ADDSTUDENTDIALOG_H

#include <QtGui/QDialog>

class QStringList;

namespace Ui {
	class AddStudentDialog;
}

class AddStudentDialog : public QDialog
{
	Q_OBJECT
public:
	AddStudentDialog(QWidget *parent = 0);
	~AddStudentDialog();

	QString firstName() const;
	QString lastName() const;
	QStringList checkedApplicationNames() const;
	void setApplicationNames(QStringList applicationNames);

private:
	Ui::AddStudentDialog *m_ui;

	void setValid();
	void setInvalid();

private slots:
	void addClicked();
	void validate();

};

#endif // ADDSTUDENTDIALOG_H
