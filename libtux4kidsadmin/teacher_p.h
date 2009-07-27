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

	QString firstName;
	QString lastName;

};

#endif // TEACHER_P_H
