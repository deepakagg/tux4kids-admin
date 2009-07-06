#include "tuxmathPlugin.h"

TuxmathPlugin::TuxmathPlugin(QObject *parent) : QObject(parent)
{
}

TuxmathPlugin::~TuxmathPlugin()
{
}

QString TuxmathPlugin::name() const
{
	return tr("tuxmath plugin");
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
