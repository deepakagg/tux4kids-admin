#ifndef CLASS_H
#define CLASS_H

#include <QtGlobal>
#include <QString>

#include "libtux4kidsadmin_global.h"
#include "teacher.h"

class ClassPrivate;
class QStringList;

class LIBTUX4KIDSADMIN_SHARED_EXPORT Class
{
public:
	Class(QString name = QString());
	Class(const Class& other);
	~Class();

	QString name() const;
	void setName(QString name);
	int id() const;
	void setId(int id);
	QStringList students() const;
	void setStudents(const QStringList &students);
	QList<Teacher> teachers() const;
	void setTeachers(const QList<Teacher> &teachers);
	Class &operator=(const Class&);
	bool operator==(const Class &other) const;

protected:

	ClassPrivate * d_ptr;
	Class(ClassPrivate &dd);

private:
	Q_DECLARE_PRIVATE(Class)
};

#endif // CLASS_H
