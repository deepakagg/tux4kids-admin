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

#include "selectClassWidget.h"
#include "ui_selectClassWidget.h"

SelectClassWidget::SelectClassWidget(QWidget *parent)
		: QWidget(parent),
		m_ui(new Ui::SelectClassWidget)
{
	m_ui->setupUi(this);

	m_ui->classTable->setModel(&m_classTableProxyModel);
	connect(m_ui->clearButton, SIGNAL(clicked()), m_ui->searchEdit, SLOT(clear()));
	connect(m_ui->searchEdit, SIGNAL(textEdited(QString)), this, SLOT(searchEdited()));
	connect(&m_searchTimer, SIGNAL(timeout()), this, SLOT(updateFilter()));
}

SelectClassWidget::~SelectClassWidget()
{
	delete m_ui;
}

void SelectClassWidget::setClassTableModel(ClassTableModel *classTableModel)
{
	m_classTableProxyModel.setSourceModel(classTableModel);
}

QTableView *SelectClassWidget::classTable()
{
	return m_ui->classTable;
}

void SelectClassWidget::searchEdited()
{
	m_searchTimer.start(250);
}

void SelectClassWidget::updateFilter()
{
	m_classTableProxyModel.setFilterRegExp(m_ui->searchEdit->text());
}

QModelIndex SelectClassWidget::selectedClassIndex()
{
	QModelIndex proxyIndex = m_ui->classTable->selectionModel()->selectedIndexes().first();
	return m_classTableProxyModel.mapToSource(proxyIndex);
}

