#ifndef MANAGESTUDENTSWIDGET_H
#define MANAGESTUDENTSWIDGET_H

#include <QtGui/QWidget>
#include <QPointer>

class AddStudentDialog;

namespace Ui {
	class ManageStudentsWidget;
}

class ManageStudentsWidget : public QWidget
{
	Q_OBJECT
public:
	ManageStudentsWidget(QWidget *parent = 0);
	~ManageStudentsWidget();

private:
	Ui::ManageStudentsWidget *m_ui;
	QPointer<AddStudentDialog> addStudentDialog;

private slots:

	void addStudentClicked();
};

#endif // MANAGESTUDENTSWIDGET_H
