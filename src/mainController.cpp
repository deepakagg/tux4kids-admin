#include <QDebug>

#include "mainController.h"

MainController::MainController()
{
	pluginManager.loadPlugins();

	if (pluginManager.empty()) {
		qDebug() << tr("Failed to load plugins");
	}
}

MainController::~MainController()
{
}

