#include <QDir>
#include <QDebug>

#include "pluginManager.h"

PluginManager::PluginManager(QString pluginsPath, QObject *parent) : QAbstractListModel(parent)
{
	m_pluginsPath = pluginsPath;
}

int PluginManager::rowCount(const QModelIndex &parent) const
{
	return m_plugins.size();
}

QVariant PluginManager::data(const QModelIndex &index, int role) const
{
	if (!index.isValid())
		return QVariant();

	if (index.row() >= rowCount())
		return QVariant();

	if (role == Qt::DisplayRole) {
		QString result = m_pluginNames.at(index.row());
		if (m_plugins.at(index.row())->isLoaded()) {
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
				m_pluginNames.append(pluginInterface->name());
				m_plugins.append(pluginLoader);
				//delete pluginInterface;
				//pluginLoader->unload();
			}
		}
	}
}

bool PluginManager::empty() const
{
	return m_plugins.empty();
}

void PluginManager::setPluginsPath(QString pluginsPath)
{
	m_pluginsPath = pluginsPath;
}

bool PluginManager::load(int pluginIndex)
{
	bool result = m_plugins.at(pluginIndex)->load();
	emit dataChanged(index(pluginIndex, 0), index(pluginIndex, 0));
	return result;
}

bool PluginManager::unload(int pluginIndex)
{
	bool result = m_plugins.at(pluginIndex)->unload();
	emit dataChanged(index(pluginIndex, 0), index(pluginIndex, 0));
	return result;
}

QPluginLoader &PluginManager::operator[](int i)
{
	return *m_plugins[i];
}

QStringList PluginManager::loadedPluginNames() const
{
	QStringList result;
	foreach (QPluginLoader *loader, m_plugins) {
		if (loader->isLoaded()) {
			PluginInterface * plugin = qobject_cast<PluginInterface *>(loader->instance());
			if (plugin) {
				result.append(plugin->name());
			}
		}
	}
	return result;
}

