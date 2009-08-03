#ifndef MANAGETEACHERSWIDGET_H
#define MANAGETEACHERSWIDGET_H

#include <QtGui/QWidget>
#include <QPointer>

#include "teacherTableProxyModel.h"

namespace Ui {
	class ManageTeachersWidget;
}

class MainController;
class EditTeacherDialog;

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
	QPointer<EditTeacherDialog> m_addTeacherDialog;
	QPointer<EditTeacherDialog> m_editTeacherDialog;
	void setEditButtonsEnabled(bool enable);

private slots:
	void addClicked();
	void editClicked();
	void deleteClicked();
	void addAccepted();
	void addRejected();
	void editAccepted();
	void editRejected();
	void setEditButtons();

};

#endif // MANAGETEACHERSWIDGET_H
