#include <QDebug>
#include <QApplication>
#include <QDir>

#include "mainController.h"
#include "schoolData.h"
#include "profileDirFactory.h"

MainController::MainController(QObject *parent)
		: QObject(parent)
{
	m_pluginManager.setPluginsPath(qApp->applicationDirPath() + "/plugins");
	m_pluginManager.loadPlugins();

	if (m_pluginManager.empty()) {
		qDebug() << tr("Failed to load plugins");
	}

	m_schoolData = new SchoolData(QDir::homePath() + "/school_data");
	m_studentTableModel.setSchoolData(m_schoolData);
	m_classTableModel.setSchoolDatabase(m_schoolData->schoolDatabase());
	m_teacherTableModel.setSchoolDatabase(m_schoolData->schoolDatabase());
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

ClassTableModel *MainController::classTableModel()
{
	return &m_classTableModel;
}

TeacherTableModel *MainController::teacherTableModel()
{
	return &m_teacherTableModel;
}

