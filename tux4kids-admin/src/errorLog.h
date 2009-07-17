#ifndef ERRORLOG_H
#define ERRORLOG_H

class QFile;

class ErrorLog
{
public:
	ErrorLog();
	static ErrorLog* Instance();
	static void Destroy();
	static void log(const QString &message, const QString &userMessage = QString());

protected:
	static ErrorLog* instance;

	QFile *logFile;
};

#endif // ERRORLOG_H
