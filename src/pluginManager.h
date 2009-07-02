#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

#include <QAbstractListModel>

#include "pluginInterface.h"


class PluginManager : public QAbstractListModel
{
	Q_OBJECT

public:
	PluginManager();

	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
	bool empty() const;
	void loadPlugins();

private:
	QList<PluginInterface *> plugins;


};

#endif // PLUGINMANAGER_H
