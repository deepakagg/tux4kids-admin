/*

This file is part of Tux4kids-admin Tuxmath plugin

Tux4kids-admin Tuxmath plugin is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or any later version.

Tux4kids-admin Tuxmath plugin is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Tux4kids-admin Tuxmath plugin.  If not, see <http://www.gnu.org/licenses/>.

Author: Michał Świtakowski <tux4kids at_here switakowski.com>, Copyright (C) 2009

*/

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
