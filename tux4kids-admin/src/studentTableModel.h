#ifndef STUDENTTABLEMODEL_H
#define STUDENTTABLEMODEL_H

#include <QAbstractTableModel>
#include <QPointer>
#include <QList>

class StudentDir;
class SchoolData;
class Class;

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
	QStringList selectedStudentsDirNames() const;
	QList<StudentDir *> selectedStudents() const;
	void setSelectedStudents(const QStringList &selectedStudentsDirNames);
	void clearSelection();
	StudentDir *studentAt(int i);

	void setSchoolData(SchoolData *schoolData);
	int computerCount() const;

	enum StudentField {
		StudentSelected = 0,
		StudentFirstName = 1,
		StudentLastName = 2,
		StudentComputer = 3
	};

protected:

	QList<StudentDir *> m_students;
	QList<bool> m_studentsSelection;
	QPointer<SchoolData> m_schoolData;

private slots:
	void addStudent(StudentDir *newStudent);
	void addClass(Class &newClass);
	void updateClass(Class &updatedClass);
	void deleteClass(Class &deletedClass);
};

#endif // STUDENTTABLEMODEL_H
