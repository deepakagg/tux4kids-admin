#ifndef APPLICATIONDIR_H
#define APPLICATIONDIR_H

#include <QObject>
#include <QString>

class ApplicationDir : public QObject
{
public:
	ApplicationDir(QObject *parent = 0);
	virtual QString foo();
};

#endif // APPLICATIONDIR_H
