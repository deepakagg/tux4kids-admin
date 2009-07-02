#ifndef PLUGINMANAGERDIALOG_H
#define PLUGINMANAGERDIALOG_H

#include <QtGui/QDialog>

#include "pluginManager.h"

namespace Ui {
	class PluginManagerDialog;
}

class PluginManagerDialog : public QDialog
{
	Q_OBJECT
	Q_DISABLE_COPY(PluginManagerDialog)
public:
	explicit PluginManagerDialog(PluginManager *newPluginManager, QWidget *parent = 0);
	virtual ~PluginManagerDialog();

protected:
	virtual void changeEvent(QEvent *e);

private:
	Ui::PluginManagerDialog *m_ui;

};

#endif // PLUGINMANAGERDIALOG_H
