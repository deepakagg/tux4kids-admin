#include "mainWindow.h"
#include "ui_mainWindow.h"
#include "pluginManagerDialog.h"
#include "manageStudentsWidget.h"
#include "mainController.h"

MainWindow::MainWindow(MainController *mainController, QWidget *parent) : QMainWindow(parent), m_ui(new Ui::MainWindow)
{
	m_ui->setupUi(this);

	m_mainController = mainController;
	m_ui->tabWidget->insertTab(1, new ManageStudentsWidget(m_mainController, this), tr("Students"));

	connect(m_ui->actionPlugins, SIGNAL(triggered()), this, SLOT(pluginsManagerClicked()));
}

MainWindow::~MainWindow()
{
	delete m_ui;
}

void MainWindow::pluginsManagerClicked()
{
	PluginManagerDialog pluginManagerDialog(m_mainController->pluginManager(), this);
	pluginManagerDialog.exec();
}
