#include <QDebug>
#include <QFile>

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
	logFile	= new QFile(ApplicationInfo::errorLogDir() + "/log.txt");
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

void ErrorLog::log(QString message, QString userMessage)
{
	instance = ErrorLog::Instance();
	qDebug() << message << " message for user: " << userMessage;
}
