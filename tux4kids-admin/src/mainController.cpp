#include <QDebug>
#include <QApplication>
#include <QDir>

#include "mainController.h"
#include "schoolData.h"

MainController::MainController()
{
	m_pluginManager.setPluginsPath(qApp->applicationDirPath() + "/plugins");
	m_pluginManager.loadPlugins();

	if (m_pluginManager.empty()) {
		qDebug() << tr("Failed to load plugins");
	}

	m_schoolData = new SchoolData(QDir::homePath() + "/school_data");
	m_studentTableModel.setSchoolData(m_schoolData);
}

MainController::~MainController()
{
	delete m_schoolData;
}

PluginManager *MainController::pluginManager()
{
	return &m_pluginManager;
}

SchoolData *MainController::schoolData()
{
	return m_schoolData;
}

StudentTableModel *MainController::studentTableModel()
{
	return &m_studentTableModel;
}


