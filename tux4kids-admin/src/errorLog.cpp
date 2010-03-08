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

#include <QDebug>
#include <QFile>
#include <QDateTime>
#include <QMessageBox>

#include "errorLog.h"
#include "applicationInfo.h"

ErrorLog* ErrorLog::instance = 0;

class ErrorLogCleaner
{
public:
	~ErrorLogCleaner()
	{
		ErrorLog::Destroy();
	}
} SingletonCleanerInstance;

ErrorLog::ErrorLog()
{
	QString logFileName = "log-" + QDateTime::currentDateTime().toString(Qt::ISODate) + ".txt";
	logFile	= new QFile(ApplicationInfo::errorLogDir() + "/" + logFileName);
}

ErrorLog* ErrorLog::Instance()
{
	if(instance == 0)
	{
		instance = new ErrorLog();
	}
	return instance;
}

void ErrorLog::Destroy()
{
	if(instance != 0)
	{
		delete instance;
		instance = 0;
	}
}

void ErrorLog::log(const QString &message, const QString &userMessage)
{
	instance = ErrorLog::Instance();

	if (!userMessage.isEmpty()) {
		QMessageBox *msgBox = new QMessageBox(QMessageBox::Warning, "Tux4kids-admin", userMessage, QMessageBox::Ok);
		msgBox->setAttribute(Qt::WA_DeleteOnClose, true);
		msgBox->show();
	}

	if(!instance->logFile->open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
		qDebug() << QObject::tr("Failed to open log file for writing");
	} else {
		QDataStream out(instance->logFile);
		out << message << "\n";
		instance->logFile->close();
	}
}
