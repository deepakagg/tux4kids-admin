#ifndef PLUGIN_INTERFACE_H
#define PLUGIN_INTERFACE_H

#include <QString>
#include <QtPlugin>

//class ProfileDir;
class SchoolData;

class PluginInterface
{
public:
	virtual ~PluginInterface() {}

	virtual QString name() const = 0;
	virtual QString version() const = 0;

//	virtual ProfileDir *newProfileDir(QString path) const = 0;
	virtual void setSchoolData(SchoolData *schoolData) = 0;

	virtual QWidget *mainWidget() = 0;

protected:

	SchoolData *m_schoolData;

};

Q_DECLARE_INTERFACE(PluginInterface, "org.Tux4Kids.Tux4KidsPluginInterface/0.0.2");

#endif
