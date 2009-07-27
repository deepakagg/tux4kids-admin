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

	void setSchoolDatabase(SchoolDatabase *schoolDatabase);
private:

	enum ClassField {
		ClassSelected = 0,
		ClassName = 1,
	};
	QPointer<SchoolDatabase> m_schoolDatabase;
	QList<Class> m_classes;
};

#endif // CLASSTABLEMODEL_H
