#ifndef MANAGETEACHERSWIDGET_H
#define MANAGETEACHERSWIDGET_H

#include <QtGui/QWidget>

namespace Ui {
	class ManageTeachersWidget;
}

class ManageTeachersWidget : public QWidget
{
	Q_OBJECT
public:
	ManageTeachersWidget(QWidget *parent = 0);
	~ManageTeachersWidget();

private:
	Ui::ManageTeachersWidget *m_ui;
};

#endif // MANAGETEACHERSWIDGET_H
