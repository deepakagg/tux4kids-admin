#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QObject>
#include <QList>

#include "pluginManager.h"
#include "studentTableModel.h"

class SchoolData;

class MainController : public QObject
{
	Q_OBJECT

public:
	MainController();
	~MainController();

	PluginManager *pluginManager();
	SchoolData *schoolData();
	StudentTableModel *studentTableModel();

private:

	PluginManager m_pluginManager;
	StudentTableModel m_studentTableModel;
	QPointer<SchoolData> m_schoolData;

};

#endif // MAINCONTROLLER_H
