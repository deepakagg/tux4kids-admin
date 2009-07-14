#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QObject>
#include <QList>

#include "pluginManager.h"

class SchoolData;

class MainController : public QObject
{
	Q_OBJECT

public:
	MainController();
	~MainController();

	PluginManager *pluginManager();
	SchoolData *schoolData();

private:

	PluginManager m_pluginManager;
	QPointer<SchoolData> m_schoolData;

};

#endif // MAINCONTROLLER_H
