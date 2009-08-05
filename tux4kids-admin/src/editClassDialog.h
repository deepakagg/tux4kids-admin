#ifndef EDITCLASSDIALOG_H
#define EDITCLASSDIALOG_H

#include <QtGui/QDialog>

#include "studentTableModel.h"


namespace Ui {
	class EditClassDialog;
}

class Class;
class SelectStudentWidget;
class SchoolData;
class SelectTeacherWidget;

class EditClassDialog : public QDialog
{
	Q_OBJECT
public:
	EditClassDialog(SchoolData *schoolData, QWidget *parent = 0);
	~EditClassDialog();

	Class getClass() const;
	void setClass(const Class & newClass);

private:
	Ui::EditClassDialog *m_ui;
	SelectStudentWidget *m_selectStudentWidget;
	SelectTeacherWidget *m_selectTeacherWidget;
	SchoolData *m_schoolData;

	bool isValid() const;

private slots:
	void validate();

};

#endif // EDITCLASSDIALOG_H

