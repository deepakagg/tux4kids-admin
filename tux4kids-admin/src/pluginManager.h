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
