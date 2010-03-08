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
