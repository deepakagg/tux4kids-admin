#ifndef TEACHERTABLEMODEL_H
#define TEACHERTABLEMODEL_H

#include <QAbstractTableModel>
#include <QPointer>

#include "teacher.h"

class SchoolDatabase;

class TeacherTableModel : public QAbstractTableModel
{
	Q_OBJECT
public:
	TeacherTableModel(QObject *parent = 0);
	void setSchoolDatabase(SchoolDatabase *schoolDatabase);
	int columnCount(const QModelIndex &parent = QModelIndex()) const;
	int rowCount(const QModelIndex &parent = QModelIndex()) const;

protected:

	enum TeacherField {
		TeacherSelected = 0,
		TeacherFirstName = 1,
		TeacherLastName = 2
	};

	QPointer<SchoolDatabase> m_schoolDatabase;
	QList<Teacher> m_teachers;

private slots:
	void addTeacher(const Teacher &teacher);
	void updateTeacher(const Teacher &teacher);
	void deleteTeacher(const Teacher &teacher);

};

#endif // TEACHERTABLEMODEL_H
