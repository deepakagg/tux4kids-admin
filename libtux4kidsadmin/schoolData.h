#ifndef SCHOOLDATA_H
#define SCHOOLDATA_H

#include <QObject>

class QString;
class SchoolDataPrivate;
class StudentDir;

class SchoolData : public QObject
{
	Q_OBJECT
public:
	SchoolData(QString path, QObject *parent = 0);
	~SchoolData();
	
	enum Status {
		NoError = 0,
		InitializationError = 1
	};

	Status status() const;
	StudentDir *addStudent();

protected:
	SchoolDataPrivate * const d_ptr;
	SchoolData(SchoolDataPrivate &dd, QObject *parent = 0);

private:
	Q_DECLARE_PRIVATE(SchoolData)
	Q_DISABLE_COPY(SchoolData)
};

#endif // SCHOOLDATA_H
