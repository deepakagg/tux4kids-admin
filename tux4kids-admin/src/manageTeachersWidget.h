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
class SelectTeacherWidget;
class SchoolDatabase;

class ManageTeachersWidget : public QWidget
{
	Q_OBJECT
public:
	ManageTeachersWidget(MainController *mainController, QWidget *parent = 0);
	~ManageTeachersWidget();

private:
	Ui::ManageTeachersWidget *m_ui;
	QPointer<MainController> m_mainController;
	QPointer<EditTeacherDialog> m_addTeacherDialog;
	QPointer<EditTeacherDialog> m_editTeacherDialog;
	QPointer<SelectTeacherWidget> m_selectTeacherWidget;
	QPointer<SchoolDatabase> m_schoolDatabase;

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
