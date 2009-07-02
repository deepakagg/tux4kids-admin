#include "pluginManagerDialog.h"
#include "ui_pluginManagerDialog.h"

PluginManagerDialog::PluginManagerDialog(PluginManager *newPluginManager, QWidget *parent) : QDialog(parent), m_ui(new Ui::PluginManagerDialog)
{
	m_ui->setupUi(this);
	m_ui->pluginsList->setModel(newPluginManager);
}

PluginManagerDialog::~PluginManagerDialog()
{
	delete m_ui;
}

void PluginManagerDialog::changeEvent(QEvent *e)
{
	QDialog::changeEvent(e);
	switch (e->type()) {
	case QEvent::LanguageChange:
		m_ui->retranslateUi(this);
		break;
	default:
		break;
	}
}
