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

	void setSchoolDatabase(SchoolDatabase *schoolDatabase);
private:

	enum ClassField {
		ClassSelected = 0,
		ClassName = 1,
	};
	QPointer<SchoolDatabase> m_schoolDatabase;
	QList<Class> m_classes;
	QList<bool> m_classesSelection;
};

#endif // CLASSTABLEMODEL_H
