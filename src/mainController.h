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

private:

	PluginManager pluginManager;
};

#endif // MAINCONTROLLER_H
