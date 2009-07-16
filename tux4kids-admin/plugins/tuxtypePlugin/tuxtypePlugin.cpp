#include <QDebug>

#include "tuxtypePlugin.h"

TuxtypePlugin::TuxtypePlugin(QObject *parent) : QObject(parent)
{
	qDebug() << "tux type plugin constructed";
}

TuxtypePlugin::~TuxtypePlugin()
{
	qDebug() << "tux type plugin destroyed";
}

QString TuxtypePlugin::name() const
{
	return "tuxtype";
}

QString TuxtypePlugin::version() const
{
	return "0.0.1";
}

QWidget *TuxtypePlugin::mainWidget()
{
	return m_mainWidget;
}

Q_EXPORT_PLUGIN2(TuxtypePlugin, TuxtypePlugin);
