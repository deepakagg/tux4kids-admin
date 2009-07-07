#include <QDir>
#include <QDebug>

#ifdef Q_WS_X11
#include <sys/stat.h>
#endif

#include "applicationInfo.h"

ApplicationInfo::ApplicationInfo()
{
}

QString ApplicationInfo::name()
{
	return "tux4kids-admin";
}

QString ApplicationInfo::version()
{
	return "0.0.1";
}

QString ApplicationInfo::configurationDir()
{

#if defined(Q_WS_X11) || defined(Q_WS_MAC)
	QString confDirName = ".tux4kids-admin";
#elif defined Q_WS_WIN
	QString confDirName = "tux4kids-admin";
#endif

	QDir confDir(QDir::homePath() + "/" + confDirName);
	if(!confDir.exists()) {
		QDir homeDir = QDir::home();
		homeDir.mkdir(confDirName);
#if defined(Q_WS_X11) || defined(Q_WS_MAC)
		chmod(QFile::encodeName(confDir.path()), 0700);
#endif
	}
	return confDir.absolutePath();

}

QString ApplicationInfo::errorLogDir()
{
	QString errorDirPath(configurationDir() + "/error log");
	QDir errorDir(errorDirPath);

	if(!errorDir.exists()) {
		QDir confDir(ApplicationInfo::configurationDir());
		confDir.mkdir("error log");
	}
	return errorDirPath;
}
