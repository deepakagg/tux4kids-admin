#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QObject>
#include <QList>

#include "pluginManager.h"
#include "studentTableModel.h"
#include "classTableModel.h"

class SchoolData;

class MainController : public QObject
{
	Q_OBJECT

public:
	MainController(QObject *parent = 0);
	~MainController();

	PluginManager *pluginManager();
	SchoolData *schoolData();
	StudentTableModel *studentTableModel();
	ClassTableModel *classTableModel();

private:

	PluginManager m_pluginManager;
	StudentTableModel m_studentTableModel;
	ClassTableModel m_classTableModel;
	QPointer<SchoolData> m_schoolData;

};

#endif // MAINCONTROLLER_H
