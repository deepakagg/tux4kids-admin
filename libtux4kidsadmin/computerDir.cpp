#include "computerDir.h"
#include "computerDir_p.h"

/**************************** ComputerPrivate *************************/

ComputerDirPrivate::ComputerDirPrivate(QString path, int num)
{
	QDir parentDir(path);
	QString dirName = QString("computer_%1").arg(number);
	if (!parentDir.exists(dirName)) {
		if (!parentDir.mkdir(dirName)) {
			//report error
		}
	}
	mainDir.setPath(parentDir.absoluteFilePath(dirName));
	number = num;
}

ComputerDirPrivate::~ComputerDirPrivate()
{
}

/**************************** ComputerDir *************************/

ComputerDir::ComputerDir(QString path, int number, QObject *parent)
		: QObject(parent),
		d_ptr(new ComputerDirPrivate(path, number))
{
	Q_D(ComputerDir);
	d->q_ptr = this;
}

ComputerDir::ComputerDir(ComputerDirPrivate &dd, QObject *parent)
		: QObject(parent), d_ptr(&dd)
{
	Q_D(ComputerDir);
	d->q_ptr = this;
}

ComputerDir::~ComputerDir()
{
}

