#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>

#include "mainController.h"

namespace Ui
{
	class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(MainController *controller, QWidget *parent = 0);
	~MainWindow();

private:
	Ui::MainWindow *m_ui;

	MainController *mainController;

private slots:
	void pluginsManagerClicked();

};

#endif // MAINWINDOW_H
