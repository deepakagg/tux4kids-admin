#include "mainWindow.h"
#include "ui_mainWindow.h"
#include "pluginManagerDialog.h"
#include "manageStudentsWidget.h"

MainWindow::MainWindow(MainController *controller, QWidget *parent) : QMainWindow(parent), m_ui(new Ui::MainWindow)
{
	m_ui->setupUi(this);

	mainController = controller;
	//m_ui->tabWidget->insertTab(1, new ManageStudentsWidget(this), tr("Students"));

	connect(m_ui->actionPlugins, SIGNAL(triggered()), this, SLOT(pluginsManagerClicked()));
}

MainWindow::~MainWindow()
{
	delete m_ui;
}

void MainWindow::pluginsManagerClicked()
{
	PluginManagerDialog pluginManagerDialog(mainController->pluginManager(), this);
	pluginManagerDialog.exec();
}
