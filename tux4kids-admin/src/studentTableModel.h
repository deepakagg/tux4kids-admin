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
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);

	void setSchoolData(const SchoolData *schoolData);

	enum StudentField {
		StudentSelected = 0,
		StudentFirstName = 1,
		StudentLastName = 2
	};

protected:

	QList< QPointer<StudentDir> > m_students;
	QList<bool> m_studentsSelection;

private slots:
	void addStudent(StudentDir *newStudent);
};

#endif // STUDENTTABLEMODEL_H
