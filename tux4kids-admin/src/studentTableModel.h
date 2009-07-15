#ifndef STUDENTTABLEMODEL_H
#define STUDENTTABLEMODEL_H

#include <QAbstractTableModel>
#include <QPointer>
#include <QList>

class StudentDir;
class SchoolData;

class StudentTableModel : public QAbstractTableModel
{
	Q_OBJECT
public:
	StudentTableModel(QObject *parent = 0);
	~StudentTableModel();

	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	int columnCount(const QModelIndex &parent = QModelIndex()) const;
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

	void setSchoolData(const SchoolData *schoolData);

protected:

	enum StudentField {
		StudentFirstName = 0,
		StudentLastName = 1
	};

	QList< QPointer<StudentDir> > m_students;

private slots:
	void addStudent(StudentDir *newStudent);
};

#endif // STUDENTTABLEMODEL_H
