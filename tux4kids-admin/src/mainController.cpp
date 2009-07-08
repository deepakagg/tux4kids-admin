#include <QDebug>
#include <QApplication>

#include "mainController.h"
#include "applicationDir.h"
#include "applicationDirTuxmath.h"

MainController::MainController()
{
	m_pluginManager.setPluginsPath(qApp->applicationDirPath() + "/plugins");
	m_pluginManager.loadPlugins();

	if (m_pluginManager.empty()) {
		qDebug() << tr("Failed to load plugins");
	}

	qDebug() << "let's create ApplicationDir object";
	ApplicationDir appdir;
	qDebug() << "it said" << appdir.foo();

	qDebug() << "let's create ApplicationDir object";
	ApplicationDirTuxmath appdir2;
	qDebug() << "it said" << appdir2.foo();


}

MainController::~MainController()
{
}

PluginManager *MainController::pluginManager()
{
	return &m_pluginManager;
}


