#ifndef MANAGECLASSESWIDGET_H
#define MANAGECLASSESWIDGET_H

#include <QtGui/QWidget>
#include <QPointer>

#include "classTableProxyModel.h"

namespace Ui {
	class ManageClassesWidget;
}

class MainController;
class ManageClassDialog;

class ManageClassesWidget : public QWidget
{
	Q_OBJECT
public:
	ManageClassesWidget(MainController *mainController, QWidget *parent = 0);
	~ManageClassesWidget();

private:
	Ui::ManageClassesWidget *m_ui;

	QPointer<MainController> m_mainController;
	QPointer<ManageClassDialog> m_addClassDialog;
	ClassTableProxyModel m_classTableProxyModel;

private slots:
	void addClicked();
};

#endif // MANAGECLASSESWIDGET_H
