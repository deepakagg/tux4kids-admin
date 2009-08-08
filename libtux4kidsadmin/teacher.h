#ifndef TEACHER_H
#define TEACHER_H

#include <QtGlobal>
#include <QString>
#include <QList>

#include "libtux4kidsadmin_global.h"
#include "class.h"

class TeacherPrivate;

class LIBTUX4KIDSADMIN_SHARED_EXPORT Teacher
{
public:
	Teacher();
	Teacher(QString firstName, QString lastName);
	Teacher(const Teacher &other);
	~Teacher();

	QString firstName() const;
	QString lastName() const;
	int id() const;
	void setFirstName(QString firstName);
	void setLastName(QString lastName);
	void setId(int id);
	Teacher &operator=(const Teacher &other);
	bool operator==(const Teacher &other) const;
	QList<Class> *classes();

protected:

	TeacherPrivate * d_ptr;
	Teacher(TeacherPrivate &dd);

private:
	Q_DECLARE_PRIVATE(Teacher)
};

#endif // TEACHER_H
