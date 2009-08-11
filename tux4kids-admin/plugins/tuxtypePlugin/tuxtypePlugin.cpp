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
	return 0;
}

void TuxtypePlugin::setSchoolData(SchoolData *schoolData)
{
	m_schoolData = schoolData;
}

Q_EXPORT_PLUGIN2(TuxtypePlugin, TuxtypePlugin);
