/*

This file is part of Tux4kids-admin Dummy plugin

Tux4kids-admin Dummy plugin is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or any later version.

Tux4kids-admin Dummy plugin is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Tux4kids-admin Dummy plugin.  If not, see <http://www.gnu.org/licenses/>.

Author: Michał Świtakowski <tux4kids at_here switakowski.com>, Copyright (C) 2009

*/

#ifndef DUMMY_PLUGIN_H
#define DUMMY_PLUGIN_H

#include <QObject>

#include "pluginInterface.h"

class DummyPlugin : public QObject, PluginInterface
{
	Q_OBJECT
	Q_INTERFACES(PluginInterface)

public:
	DummyPlugin(QObject *parent = 0);
	~DummyPlugin();

	QString name() const;
	QString version() const;
	QWidget *mainWidget();
	void setSchoolData(SchoolData *schoolData);


};

#endif
