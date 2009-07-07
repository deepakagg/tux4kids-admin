#ifndef APPLICATIONINFO_H
#define APPLICATIONINFO_H

#include <QString>

class ApplicationInfo
{
	public:
	ApplicationInfo();

	static QString name();
	static QString version();

	static QString configurationDir();
	static QString errorLogDir();

};

#endif // APPLICATIONINFO_H
