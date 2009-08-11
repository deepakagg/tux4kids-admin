#include <QDebug>

#include "tuxmathPlugin.h"
#include "tuxmathOptions.h"

#include "schoolData.h"
#include "tuxmathMainWidget.h"


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
	return (new TuxmathMainWidget(m_schoolData));
}

void TuxmathPlugin::setSchoolData(SchoolData *schoolData)
{
	m_schoolData = schoolData;
}

Q_EXPORT_PLUGIN2(TuxmathPlugin, TuxmathPlugin);
