#include "applicationDir.h"

ApplicationDir::ApplicationDir(QObject *parent) : QObject(parent)
{
}

QString ApplicationDir::foo()
{
	return "general";
}

