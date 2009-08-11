#ifndef TUXTYPE_PLUGIN_H
#define TUXTYPE_PLUGIN_H

#include <QObject>

#include "pluginInterface.h"

class TuxtypePlugin : public QObject, PluginInterface
{
	Q_OBJECT
	Q_INTERFACES(PluginInterface)

public:
	TuxtypePlugin(QObject *parent = 0);
	~TuxtypePlugin();

	QString name() const;
	QString version() const;
	QWidget *mainWidget();
	void setSchoolData(SchoolData *schoolData);


};

#endif
