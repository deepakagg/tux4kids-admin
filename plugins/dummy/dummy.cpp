#include "dummy.h"

DummyPlugin::DummyPlugin(QObject *parent) : QObject(parent)
{
}

DummyPlugin::~DummyPlugin()
{
}

QString DummyPlugin::name() const
{
	return tr("dummy plugin");
}

QString DummyPlugin::version() const
{
	return "0.1";
}

Q_EXPORT_PLUGIN2(DummyPlugin, DummyPlugin);
