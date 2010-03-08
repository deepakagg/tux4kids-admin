/*

This file is part of Tux4kids-admin Tuxmath plugin

Tux4kids-admin Tuxmath plugin is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or any later version.

Tux4kids-admin Tuxmath plugin is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Tux4kids-admin Tuxmath plugin.  If not, see <http://www.gnu.org/licenses/>.

Author: Michał Świtakowski <tux4kids at_here switakowski.com>, Copyright (C) 2009

*/

#ifndef TUXMATHMAINWIDGET_H
#define TUXMATHMAINWIDGET_H

#include <QtGui/QWidget>
#include <QPointer>

#include "studentTableModel.h"

namespace Ui {
	class TuxmathMainWidget;
}

class SchoolData;
class SelectStudentWidget;

class TuxmathMainWidget : public QWidget {
	Q_OBJECT
	Q_DISABLE_COPY(TuxmathMainWidget)
public:
	explicit TuxmathMainWidget(SchoolData *schoolData, QWidget *parent = 0);
	virtual ~TuxmathMainWidget();

private:
	Ui::TuxmathMainWidget *m_ui;
	StudentTableModel m_studentTableModel;
	QPointer<SelectStudentWidget> m_selectStudentWidget;

private slots:
	void setOptionsClicked();

};

#endif // TUXMATHMAINWIDGET_H
