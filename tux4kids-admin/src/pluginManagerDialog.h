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
	PluginManager *m_pluginManager;

private slots:
	void loadClicked();
	void unloadClicked();

};

#endif // PLUGINMANAGERDIALOG_H
