#ifndef MANAGESTUDENTSWIDGET_H
#define MANAGESTUDENTSWIDGET_H

#include <QtGui/QWidget>
#include <QPointer>

#include "studentTableProxyModel.h"
//#include "mainController.h"

class AddStudentDialog;
class MainController;

namespace Ui {
	class ManageStudentsWidget;
}

class ManageStudentsWidget : public QWidget
{
	Q_OBJECT
public:
	ManageStudentsWidget(MainController *mainController, QWidget *parent = 0);
	~ManageStudentsWidget();

private:
	Ui::ManageStudentsWidget *m_ui;
	QPointer<AddStudentDialog> m_addStudentDialog;
	QPointer<MainController> m_mainController;
	StudentTableProxyModel m_studentTableProxyModel;

	void setEditButtonsEnabled(bool enable);

private slots:

	void addStudentClicked();
	void addStudent();
	void setEditButtons();
};

#endif // MANAGESTUDENTSWIDGET_H
