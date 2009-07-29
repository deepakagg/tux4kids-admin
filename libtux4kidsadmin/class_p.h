#ifndef CLASS_P_H
#define CLASS_P_H

#include <QtGlobal>
#include <QString>
#include <QStringList>

class Teacher;

class  ClassPrivate
{
public:
	Q_DECLARE_PUBLIC(Class)

	ClassPrivate();
	virtual ~ClassPrivate();

	Class *q_ptr;

	int id;
	QString name;
	QStringList students;
	QList<Teacher> teachers;

};

#endif // CLASS_P_H
