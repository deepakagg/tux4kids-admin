#include <QtGui/QApplication>
#include <QTranslator>
#include <QLocale>
#include <QDebug>

#include "mainWindow.h"
#include "mainController.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	QTranslator translator;
	qDebug() << QLocale::system().name();
	translator.load("translations/tux4kidsadmin_" + QLocale::system().name());
	app.installTranslator(&translator);

	MainController controller;
	if (controller.status() == MainController::NoError) {
		MainWindow mainWindow(&controller);
		mainWindow.show();
		return app.exec();
	} else {
		return 1;
	}
}
