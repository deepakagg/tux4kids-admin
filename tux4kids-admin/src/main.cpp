/*

This file is part of Tux4kids-admin

Tux4kids-admin is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or any later version.

Tux4kids-admin is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Tux4kids-admin.  If not, see <http://www.gnu.org/licenses/>.

Author: Michał Świtakowski <tux4kids at_here switakowski.com>, Copyright (C) 2009

*/

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
	//qDebug() << QLocale::system().name();
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
