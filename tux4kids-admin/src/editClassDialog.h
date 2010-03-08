/*

This file is part of Tux4kids-admin

Tux4kids-admin is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or any later version.

Tux4kids-admin is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Tux4kids-admin.  If not, see <http://www.gnu.org/licenses/>.

Author: Michał Świtakowski <tux4kids at_here switakowski.com>, Copyright (C) 2009

*/

#ifndef EDITCLASSDIALOG_H
#define EDITCLASSDIALOG_H

#include <QtGui/QDialog>

#include "studentTableModel.h"
#include "teacherTableModel.h"


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

	Class getClass();
	void setClass(Class & newClass);
	void clear();

private:
	Ui::EditClassDialog *m_ui;
	SelectStudentWidget *m_selectStudentWidget;
	SelectTeacherWidget *m_selectTeacherWidget;
	SchoolData *m_schoolData;
	TeacherTableModel m_teacherTableModel;
	StudentTableModel m_studentTableModel;
	Class editedClass;

	bool isValid() const;

private slots:
	void validate();

};

#endif // EDITCLASSDIALOG_H

