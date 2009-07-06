#include <QDir>
#include <QDebug>

#include "pluginManager.h"

PluginManager::PluginManager(QString pluginsPath, QObject *parent) : QAbstractListModel(parent)
{
	m_pluginsPath = pluginsPath;
}

int PluginManager::rowCount(const QModelIndex &parent) const
{
	return plugins.size();
}

QVariant PluginManager::data(const QModelIndex &index, int role) const
{
	if (!index.isValid())
		return QVariant();

	if (index.row() >= rowCount())
		return QVariant();

	if (role == Qt::DisplayRole) {
		QString result = pluginNames.at(index.row());
		if (plugins.at(index.row())->isLoaded()) {
			result += " (loaded)";
		} else {
			result += " (not loaded)";
		}
		return result;
	}

	return QVariant();
}

void PluginManager::loadPlugins()
{
	PluginInterface *pluginInterface;
	QDir pluginsDir(m_pluginsPath);

	foreach (QString fileName, pluginsDir.entryList(QDir::Files))
	{
		QPluginLoader *pluginLoader = new QPluginLoader(pluginsDir.absoluteFilePath(fileName));
		QObject *plugin = pluginLoader->instance();
		if (plugin)
		{
			pluginInterface = qobject_cast<PluginInterface *>(plugin);
			if (pluginInterface)
			{
				pluginNames.append(pluginInterface->name());
				plugins.append(pluginLoader);
				delete pluginInterface;
				pluginLoader->unload();
			}
		}
	}
}

bool PluginManager::empty() const
{
	return plugins.empty();
}

void PluginManager::setPluginsPath(QString pluginsPath)
{
	m_pluginsPath = pluginsPath;
}

bool PluginManager::load(int pluginIndex)
{
	bool result = plugins.at(pluginIndex)->load();
	emit dataChanged(index(pluginIndex, 0), index(pluginIndex, 0));
	return result;
}

bool PluginManager::unload(int pluginIndex)
{
	bool result = plugins.at(pluginIndex)->unload();
	emit dataChanged(index(pluginIndex, 0), index(pluginIndex, 0));
	return result;
}

