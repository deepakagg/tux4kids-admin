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

#include "mainWindow.h"
#include "ui_mainWindow.h"
#include "pluginManagerDialog.h"
#include "manageStudentsWidget.h"
#include "mainController.h"
#include "manageClassesWidget.h"
#include "manageTeachersWidget.h"

#include <QDebug>

MainWindow::MainWindow(MainController *mainController, QWidget *parent) : QMainWindow(parent), m_ui(new Ui::MainWindow)
{
	m_ui->setupUi(this);

	m_mainController = mainController;

	m_ui->tabWidget->removeTab(0);
	m_ui->tabWidget->insertTab(0, new ManageStudentsWidget(m_mainController, this), tr("Students"));
	m_ui->tabWidget->insertTab(1, new ManageClassesWidget(m_mainController, this), tr("Classes"));
	m_ui->tabWidget->insertTab(2, (new ManageTeachersWidget(m_mainController, this)), tr("Teachers"));
	foreach (QPluginLoader *pluginLoader, m_mainController->pluginManager()->plugins()) {
		PluginInterface *plugin = qobject_cast<PluginInterface *>(pluginLoader->instance());
		if (plugin != 0) {
			QWidget *widget = plugin->mainWidget();
			if (widget != 0) {
				m_ui->tabWidget->insertTab(3, widget, plugin->name());
			}
		}
	}

	connect(m_ui->actionPlugins, SIGNAL(triggered()), this, SLOT(pluginsManagerClicked()));
}

MainWindow::~MainWindow()
{
	delete m_ui;
}

void MainWindow::pluginsManagerClicked()
{
	PluginManagerDialog pluginManagerDialog(m_mainController->pluginManager(), this);
	pluginManagerDialog.exec();
}
