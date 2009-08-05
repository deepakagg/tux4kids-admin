#ifndef MANAGECLASSESWIDGET_H
#define MANAGECLASSESWIDGET_H

#include <QtGui/QWidget>
#include <QPointer>

#include "classTableProxyModel.h"

namespace Ui {
	class ManageClassesWidget;
}

class MainController;
class EditClassDialog;
class SchoolDatabase;

class ManageClassesWidget : public QWidget
{
	Q_OBJECT
public:
	ManageClassesWidget(MainController *mainController, QWidget *parent = 0);
	~ManageClassesWidget();

private:
	Ui::ManageClassesWidget *m_ui;

	QPointer<MainController> m_mainController;
	QPointer<SchoolDatabase> m_schoolDatabase;
	QPointer<EditClassDialog> m_addClassDialog;
	QPointer<EditClassDialog> m_editClassDialog;
	ClassTableProxyModel m_classTableProxyModel;

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

#endif // MANAGECLASSESWIDGET_H
