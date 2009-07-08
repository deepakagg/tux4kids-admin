#include <QDebug>

#include "tuxmathPlugin.h"
#include "applicationDir.h"
#include "applicationDirTuxmath.h"

TuxmathPlugin::TuxmathPlugin(QObject *parent) : QObject(parent)
{
	qDebug() << "let's create ApplicationDir object";
	ApplicationDir appdir;
	qDebug() << "it said" << appdir.foo();

	qDebug() << "let's create ApplicationDir object";
	ApplicationDirTuxmath appdir2;
	qDebug() << "it said" << appdir2.foo();
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
