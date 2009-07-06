#ifndef TUXMATH_PLUGIN_H
#define TUXMATH_PLUGIN_H

#include <QObject>

#include "pluginInterface.h"

class TuxmathPlugin : public QObject, PluginInterface
{
	Q_OBJECT
	Q_INTERFACES(PluginInterface)

public:
	TuxmathPlugin(QObject *parent = 0);
	~TuxmathPlugin();

	QString name() const;
	QString version() const;
	QWidget *mainWidget();


};

#endif
