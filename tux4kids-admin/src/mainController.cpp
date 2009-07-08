#include <QDebug>
#include <QApplication>

#include "mainController.h"

MainController::MainController()
{
	m_pluginManager.setPluginsPath(qApp->applicationDirPath() + "/plugins");
	m_pluginManager.loadPlugins();

	if (m_pluginManager.empty()) {
		qDebug() << tr("Failed to load plugins");
	}
}

MainController::~MainController()
{
}

PluginManager *MainController::pluginManager()
{
	return &m_pluginManager;
}


