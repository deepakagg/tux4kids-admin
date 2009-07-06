#include "mainWindow.h"
#include "ui_mainWindow.h"
#include "pluginManagerDialog.h"

MainWindow::MainWindow(MainController *controller, QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	mainController = controller;

	connect(ui->actionPlugins, SIGNAL(triggered()), this, SLOT(pluginsManagerClicked()));
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::pluginsManagerClicked()
{
	PluginManagerDialog pluginManagerDialog(mainController->pluginManager(), this);
	pluginManagerDialog.exec();
}
