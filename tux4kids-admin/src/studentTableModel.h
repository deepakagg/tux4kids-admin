#ifndef STUDENTTABLEMODEL_H
#define STUDENTTABLEMODEL_H

#include <QAbstractTableModel>
#include <QPointer>

class SchoolData;

class StudentTableModel : public QAbstractTableModel
{
	Q_OBJECT
public:
	StudentTableModel(SchoolData *schoolData, QObject *parent = 0);
	~StudentTableModel();

protected:

	QPointer<SchoolData> m_schoolData;
};

#endif // STUDENTTABLEMODEL_H
