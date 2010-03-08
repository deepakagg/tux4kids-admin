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

#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

#include <QAbstractListModel>
#include <QPluginLoader>
#include <QStringList>

#include "pluginInterface.h"


class PluginManager : public QAbstractListModel
{
	Q_OBJECT

public:
	PluginManager(QString pluginsPath = QString(), QObject *parent = 0);

	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
	bool empty() const;
	void loadPlugins();
	void setPluginsPath(QString pluginsPath);
	bool load(int pluginIndex);
	bool unload(int pluginIndex);
	QPluginLoader &operator[](int i);
	QStringList loadedPluginNames() const;
	QList<QPluginLoader *> plugins();

private:
	QString m_pluginsPath;
	QList<QPluginLoader *> m_plugins;
	QStringList m_pluginNames;
	//QList<PluginInterface *> loadedPlugins;


};

#endif // PLUGINMANAGER_H
