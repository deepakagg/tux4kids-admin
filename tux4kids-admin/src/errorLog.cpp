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
