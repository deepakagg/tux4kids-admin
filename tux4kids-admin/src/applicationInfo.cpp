/*

This file is part of Tux4kids-admin

Tux4kids-admin is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or any later version.

Tux4kids-admin is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Tux4kids-admin.  If not, see <http://www.gnu.org/licenses/>.

Author: Michał Świtakowski <tux4kids at_here switakowski.com>, Copyright (C) 2009

*/

#include <QDir>
#include <QDebug>

#ifdef Q_WS_X11
#include <sys/stat.h>
#endif

#ifdef Q_WS_MAC
#include <sys/types.h>
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
