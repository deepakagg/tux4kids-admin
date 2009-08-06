#ifndef TEACHER_P_H
#define TEACHER_P_H

#include <QtGlobal>
#include <QString>

class  TeacherPrivate
{
public:
	Q_DECLARE_PUBLIC(Teacher)

	TeacherPrivate();
	virtual ~TeacherPrivate();

	Teacher *q_ptr;

	int id;
	QString firstName;
	QString lastName;
	QList<Class> classes;
};

#endif // TEACHER_P_H
