#include "pluginManagerDialog.h"
#include "ui_pluginManagerDialog.h"

PluginManagerDialog::PluginManagerDialog(PluginManager *pluginManager, QWidget *parent) : QDialog(parent), m_ui(new Ui::PluginManagerDialog)
{
	m_ui->setupUi(this);

	m_pluginManager = pluginManager;

	m_ui->pluginsList->setModel(m_pluginManager);

	connect(m_ui->loadButton, SIGNAL(clicked()), this, SLOT(loadClicked()));
	connect(m_ui->unloadButton, SIGNAL(clicked()), this, SLOT(unloadClicked()));
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

void PluginManagerDialog::loadClicked()
{
	int index = m_ui->pluginsList->selectionModel()->selectedIndexes().first().row();
	if (!m_pluginManager->load(index)) {
		//report error
	}
}

void PluginManagerDialog::unloadClicked()
{
	int index = m_ui->pluginsList->selectionModel()->selectedIndexes().first().row();
	if (!m_pluginManager->unload(index)) {
		//report error
	}
}

