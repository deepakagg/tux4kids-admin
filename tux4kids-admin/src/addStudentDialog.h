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
