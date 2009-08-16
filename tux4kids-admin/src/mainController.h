#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QObject>
#include <QList>

#include "pluginManager.h"
#include "studentTableModel.h"
#include "classTableModel.h"
#include "teacherTableModel.h"

class SchoolData;

class MainController : public QObject
{
	Q_OBJECT

public:
	MainController(QObject *parent = 0);
	~MainController();

	enum Status {
		NoError,
		InitializtionError
	};

	PluginManager *pluginManager();
	SchoolData *schoolData();
	StudentTableModel *studentTableModel();
	ClassTableModel *classTableModel();
	TeacherTableModel *teacherTableModel();
	Status status() const;

private:

	PluginManager m_pluginManager;
	StudentTableModel m_studentTableModel;
	ClassTableModel m_classTableModel;
	TeacherTableModel m_teacherTableModel;
	QPointer<SchoolData> m_schoolData;
	mutable Status m_status;

};

#endif // MAINCONTROLLER_H
