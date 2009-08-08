#ifndef EDITTEACHERDIALOG_H
#define EDITTEACHERDIALOG_H

#include <QtGui/QDialog>
#include <QPointer>

#include "schoolDatabase.h"
#include "classTableModel.h"
#include "teacher.h"

namespace Ui {
	class EditTeacherDialog;
}

class SelectClassWidget;

class EditTeacherDialog : public QDialog
{
	Q_OBJECT
public:
	EditTeacherDialog(SchoolDatabase *schoolDatabase, QWidget *parent = 0);
	~EditTeacherDialog();

	Teacher teacher();
	void setTeacher(Teacher &teacher);
	void clear();

private:
	Ui::EditTeacherDialog *m_ui;

	bool isValid() const;
	QPointer<SchoolDatabase> m_schoolDatabase;
	QPointer<SelectClassWidget> m_selectClassWidget;
	ClassTableModel m_classTableModel;
	Teacher editedTeacher;

private slots:
	void validate();
};

#endif // EDITTEACHERDIALOG_H
