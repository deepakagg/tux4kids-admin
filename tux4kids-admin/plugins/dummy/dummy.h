#ifndef DUMMY_PLUGIN_H
#define DUMMY_PLUGIN_H

#include <QObject>

#include "pluginInterface.h"

class DummyPlugin : public QObject, PluginInterface
{
	Q_OBJECT
	Q_INTERFACES(PluginInterface)

public:
	DummyPlugin(QObject *parent = 0);
	~DummyPlugin();

	QString name() const;
	QString version() const;
	QWidget *mainWidget();
	void setSchoolData(SchoolData *schoolData);


};

#endif
