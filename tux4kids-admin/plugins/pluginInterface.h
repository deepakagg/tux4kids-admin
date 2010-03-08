/*

This file is part of Tux4kids-admin

Tux4kids-admin is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or any later version.

Tux4kids-admin is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Tux4kids-admin.  If not, see <http://www.gnu.org/licenses/>.

Author: Michał Świtakowski <tux4kids at_here switakowski.com>, Copyright (C) 2009

*/


#ifndef PLUGIN_INTERFACE_H
#define PLUGIN_INTERFACE_H

#include <QString>
#include <QtPlugin>

//class ProfileDir;
class SchoolData;

class PluginInterface
{
public:
	virtual ~PluginInterface() {}

	virtual QString name() const = 0;
	virtual QString version() const = 0;

//	virtual ProfileDir *newProfileDir(QString path) const = 0;
	virtual void setSchoolData(SchoolData *schoolData) = 0;

	virtual QWidget *mainWidget() = 0;

protected:

	SchoolData *m_schoolData;

};

Q_DECLARE_INTERFACE(PluginInterface, "org.Tux4Kids.Tux4KidsPluginInterface/0.0.2");

#endif
