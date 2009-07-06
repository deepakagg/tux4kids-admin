#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QObject>
#include <QList>

#include "pluginManager.h"

class MainController : public QObject
{
	Q_OBJECT

public:
	MainController();
	~MainController();

	PluginManager *pluginManager();

private:

	PluginManager m_pluginManager;
};

#endif // MAINCONTROLLER_H
