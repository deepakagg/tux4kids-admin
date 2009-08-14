#ifndef COMPUTERDIR_H
#define COMPUTERDIR_H

#include <QObject>
#include <QDir>

class ComputerDirPrivate;
class StudentDir;

class ComputerDir : public QObject
{
	Q_OBJECT
public:
	ComputerDir(QString path, int num, QObject *parent = 0);
	~ComputerDir();

protected:
	ComputerDirPrivate * const d_ptr;
	ComputerDir(ComputerDirPrivate &dd, QObject *parent = 0);

	QDir mainDir;
	StudentDir *studentDir;

private:
	Q_DECLARE_PRIVATE(ComputerDir)
	Q_DISABLE_COPY(ComputerDir)
};

#endif // COMPUTERDIR_H
