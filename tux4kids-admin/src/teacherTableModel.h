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
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::DisplayRole);

protected:

	enum TeacherField {
		TeacherSelected = 0,
		TeacherFirstName = 1,
		TeacherLastName = 2
	};

	QPointer<SchoolDatabase> m_schoolDatabase;
	QList<Teacher> m_teachers;
	QList<bool> m_teachersSelection;

private slots:
	void addTeacher(const Teacher &teacher);
	void updateTeacher(const Teacher &teacher);
	void deleteTeacher(const Teacher &teacher);

};

#endif // TEACHERTABLEMODEL_H
