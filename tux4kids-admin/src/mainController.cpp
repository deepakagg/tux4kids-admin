#include <QDebug>
#include <QApplication>
#include <QDir>
#include <QTextStream>

#include "mainController.h"
#include "schoolData.h"
#include "profileDirFactory.h"
#include <getopt.h>

MainController::MainController(QObject *parent)
		: QObject(parent),
		m_status(NoError)
{
	QString schoolDataPath;

	int c;
	while (1) {
		static struct option long_options[] =
		{
			{"school_data_path", required_argument, 0, 'a'},
			{0, 0, 0, 0}
		};

		int option_index = 0;
		c = getopt_long(qApp->argc(), qApp->argv(), "a:", long_options, &option_index);
		if (c == -1) {
			break;
		}

		switch (c)
		{
		case 'a':
		if (optarg) {
			schoolDataPath = QString(optarg);
		} else {
			m_status = InitializtionError;
		}
		break;

		case '?':
		/* getopt_long already printed an error message.*/
		m_status = InitializtionError;
		break;

		default:
			break;
		}
	}

	if (m_status != NoError) {
		return;
	}

	m_pluginManager.setPluginsPath(qApp->applicationDirPath() + "/plugins");
	m_pluginManager.loadPlugins();

	if (m_pluginManager.empty()) {
		qDebug() << tr("Failed to load plugins");
	}

	m_schoolData = new SchoolData(schoolDataPath);
	m_studentTableModel.setSchoolData(m_schoolData);
	m_classTableModel.setSchoolDatabase(m_schoolData->schoolDatabase());
	m_teacherTableModel.setSchoolDatabase(m_schoolData->schoolDatabase());

	foreach (QPluginLoader *pluginLoader, m_pluginManager.plugins()) {
		PluginInterface *plugin = qobject_cast<PluginInterface *>(pluginLoader->instance());
		if (plugin != 0) {
			plugin->setSchoolData(m_schoolData);
		}
	}
}

MainController::~MainController()
{
	delete m_schoolData;
}

MainController::Status MainController::status() const
{
	return m_status;
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

