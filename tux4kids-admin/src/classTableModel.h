#ifndef CLASSTABLEMODEL_H
#define CLASSTABLEMODEL_H

#include <QAbstractTableModel>
#include <QPointer>

#include "class.h"

class SchoolDatabase;

class ClassTableModel : public QAbstractTableModel
{
	Q_OBJECT
public:
	ClassTableModel(QObject *parent = 0);
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
	int columnCount(const QModelIndex &parent = QModelIndex()) const;
	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::DisplayRole);
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
	QList<Class> selectedClasses() const;
	void setSelectedClasses(const QList<Class> &selectedClasses);
	void clearSelection();
	Class &at(int i);

	void setSchoolDatabase(SchoolDatabase *schoolDatabase);

	enum ClassField {
		ClassSelected = 0,
		ClassName = 1,
	};
private:
	QPointer<SchoolDatabase> m_schoolDatabase;
	QList<Class> m_classes;
	QList<bool> m_classesSelection;

private slots:
	void addClass(Class & newClass);
	void updateClass(Class &updatedClass);
	void deleteClass(Class &deletedClass);
	void addTeacher(Teacher &teacher);
	void updateTeacher(Teacher &teacher);
	void deleteTeacher(Teacher &teacher);

};

#endif // CLASSTABLEMODEL_H
