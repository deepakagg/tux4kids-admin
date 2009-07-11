#ifndef PROFILEDIR_H
#define PROFILEDIR_H

#include <QObject>

class ProfileDirPrivate;

class ProfileDir : public QObject
{
	Q_OBJECT
public:
	ProfileDir();
	~ProfileDir();
private:
	ProfileDirPrivate *d;
};

#endif // PROFILEDIR_H
