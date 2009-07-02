#include <QPluginLoader>
#include <QDir>
#include <QDebug>
#include <QApplication>

#include "pluginManager.h"

PluginManager::PluginManager()
{
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
		return plugins.at(index.row())->name();
	}

	return QVariant();
}

void PluginManager::loadPlugins()
{
	PluginInterface *pluginInterface;
	QDir pluginsDir(qApp->applicationDirPath() + "/plugins");

	foreach (QString fileName, pluginsDir.entryList(QDir::Files))
	{
		QPluginLoader pluginLoader(pluginsDir.absoluteFilePath(fileName));
		QObject *plugin = pluginLoader.instance();
		if (plugin)
		{
			pluginInterface = qobject_cast<PluginInterface *>(plugin);
			if (pluginInterface)
			{
				plugins.append(pluginInterface);
			}
		}
	}
}

bool PluginManager::empty() const
{
	return plugins.empty();
}
