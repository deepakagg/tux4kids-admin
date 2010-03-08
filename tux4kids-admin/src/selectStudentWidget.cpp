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

#include "selectStudentWidget.h"
#include "ui_selectStudentWidget.h"

SelectStudentWidget::SelectStudentWidget(QWidget *parent) :
		QWidget(parent),
		m_ui(new Ui::SelectStudentWidget)
{
	m_ui->setupUi(this);

	m_studentTableProxyModel.setSourceModel(&m_studentTableModel);

	m_ui->studentTable->setModel(&m_studentTableProxyModel);
	
#ifdef Q_WS_WIN
	m_ui->studentTable->hideColumn(StudentTableModel::StudentComputer);
#endif

	m_ui->filterKeyCombo->addItem(tr("Everything"),
				      StudentTableProxyModel::Everything);
	m_ui->filterKeyCombo->addItem(tr("First name"),
				      StudentTableProxyModel::FirstName);
	m_ui->filterKeyCombo->addItem(tr("Last name"),
				      StudentTableProxyModel::LastName);
	m_ui->filterKeyCombo->addItem(tr("Class"),
				      StudentTableProxyModel::ClassName);

	connect(m_ui->clearButton, SIGNAL(clicked()), m_ui->searchEdit, SLOT(clear()));
	connect(m_ui->searchEdit, SIGNAL(textEdited(QString)), this, SLOT(searchEdited()));
	connect(m_ui->filterKeyCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(filterKeyColumnChanged(int)));
	connect(&m_searchTimer, SIGNAL(timeout()), this, SLOT(updateFilter()));
}

SelectStudentWidget::~SelectStudentWidget()
{
	delete m_ui;
}

void SelectStudentWidget::setStudentTableModel(StudentTableModel *studentTableModel)
{
	m_studentTableProxyModel.setSourceModel(studentTableModel);
}

void SelectStudentWidget::searchEdited()
{
	m_searchTimer.start(250);
}

void SelectStudentWidget::updateFilter()
{
	m_studentTableProxyModel.setFilterRegExp(m_ui->searchEdit->text());
}

void SelectStudentWidget::filterKeyColumnChanged(int index)
{
	m_studentTableProxyModel.setFilterKeyColumn(m_ui->filterKeyCombo->itemData(index).toInt());
}

QTableView *SelectStudentWidget::studentTable()
{
	return m_ui->studentTable;
}

