#ifndef CLASS_H
#define CLASS_H

#include <QList>
#include <QPointer>
#include <QString>

class StudentDir;

class Class
{
public:
	Class(QString name = QString());

	QString name() const;
	void setName(QString name);

protected:

	QString m_name;
	QList< QPointer<StudentDir> > m_students;
};

#endif // CLASS_H
