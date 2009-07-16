#include <QDebug>

#include "tuxmathPlugin.h"

TuxmathPlugin::TuxmathPlugin(QObject *parent) : QObject(parent)
{
	qDebug() << "tux math plugin constructed";
}

TuxmathPlugin::~TuxmathPlugin()
{
	qDebug() << "tux math plugin destroyed";
}

QString TuxmathPlugin::name() const
{
	return "tuxmath";
}

QString TuxmathPlugin::version() const
{
	return "0.0.1";
}

QWidget *TuxmathPlugin::mainWidget()
{
	return m_mainWidget;
}

Q_EXPORT_PLUGIN2(TuxmathPlugin, TuxmathPlugin);
