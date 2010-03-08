/*

This file is part of Tux4kids-admin Tuxtype plugin

Tux4kids-admin Tuxtype plugin is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or any later version.

Tux4kids-admin Tuxtype plugin is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Tux4kids-admin Tuxtype plugin.  If not, see <http://www.gnu.org/licenses/>.

Author: Michał Świtakowski <tux4kids at_here switakowski.com>, Copyright (C) 2009

*/

#include <QDebug>

#include "tuxtypePlugin.h"
#include "tuxtypeMainWidget.h"

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
	return new TuxtypeMainWidget(m_schoolData);
}

void TuxtypePlugin::setSchoolData(SchoolData *schoolData)
{
	m_schoolData = schoolData;
}

Q_EXPORT_PLUGIN2(TuxtypePlugin, TuxtypePlugin);
