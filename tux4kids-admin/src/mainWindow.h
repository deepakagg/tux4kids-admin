#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QPointer>

class MainController;

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

	QPointer<MainController> m_mainController;

private slots:
	void pluginsManagerClicked();

};

#endif // MAINWINDOW_H
