#ifndef SCHOOLDATAPRIVATE_P_H
#define SCHOOLDATAPRIVATE_P_H

#include <QtGlobal>
#include <QDir>
#include "schoolData.h"
class QString;

class SchoolDataPrivate
{
public:
	Q_DECLARE_PUBLIC(SchoolData)

	SchoolDataPrivate(QString path);
	virtual ~SchoolDataPrivate();

	SchoolData *q_ptr;

	QDir mainDir;

	SchoolData::Status status;
};

#endif // SCHOOLDATAPRIVATE_P_H
