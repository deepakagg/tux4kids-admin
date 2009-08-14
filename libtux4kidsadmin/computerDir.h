#ifndef COMPUTERDIR_H
#define COMPUTERDIR_H

#include <QObject>

class ComputerDirPrivate;

class ComputerDir : public QObject
{
	Q_OBJECT
public:
	ComputerDir(QObject *parent = 0);
	~ComputerDir();

protected:
	ComputerDirPrivate * const d_ptr;
	ComputerDir(ComputerDirPrivate &dd, QObject *parent = 0);

private:
	Q_DECLARE_PRIVATE(ComputerDir)
	Q_DISABLE_COPY(ComputerDir)
};

#endif // COMPUTERDIR_H
