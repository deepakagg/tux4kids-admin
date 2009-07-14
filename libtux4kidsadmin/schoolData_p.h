#ifndef SCHOOLDATAPRIVATE_P_H
#define SCHOOLDATAPRIVATE_P_H

#include <QtGlobal>
#include <QDir>
#include <QList>
#include <QPointer>

#include "schoolData.h"

class QString;
class ProfileDir;

class SchoolDataPrivate
{
public:
	Q_DECLARE_PUBLIC(SchoolData)

	SchoolDataPrivate(QString path);
	virtual ~SchoolDataPrivate();

	SchoolData *q_ptr;

	QDir mainDir;
	SchoolData::Status status;
	QList< QPointer<ProfileDir> > profiles;
};

#endif // SCHOOLDATAPRIVATE_P_H
