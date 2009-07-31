#ifndef MANAGETEACHERSWIDGET_H
#define MANAGETEACHERSWIDGET_H

#include <QtGui/QWidget>
#include <QPointer>

#include "teacherTableProxyModel.h"

namespace Ui {
	class ManageTeachersWidget;
}

class MainController;

class ManageTeachersWidget : public QWidget
{
	Q_OBJECT
public:
	ManageTeachersWidget(MainController *mainController, QWidget *parent = 0);
	~ManageTeachersWidget();

private:
	Ui::ManageTeachersWidget *m_ui;
	QPointer<MainController> m_mainController;
	TeacherTableProxyModel m_teacherTableProxyModel;
};

#endif // MANAGETEACHERSWIDGET_H
