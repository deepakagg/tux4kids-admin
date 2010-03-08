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

QWidget *DummyPlugin::mainWidget()
{
	return 0;
}

void DummyPlugin::setSchoolData(SchoolData *schoolData)
{
	m_schoolData = schoolData;
}

Q_EXPORT_PLUGIN2(DummyPlugin, DummyPlugin);
