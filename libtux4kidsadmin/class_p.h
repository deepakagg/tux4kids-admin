#ifndef CLASS_P_H
#define CLASS_P_H

#include <QtGlobal>
#include <QString>

class  ClassPrivate
{
public:
	Q_DECLARE_PUBLIC(Class)

	ClassPrivate();
	virtual ~ClassPrivate();

	Class *q_ptr;

	int id;
	QString name;

};

#endif // CLASS_P_H
