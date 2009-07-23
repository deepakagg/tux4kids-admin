#ifndef MANAGECLASSDIALOG_H
#define MANAGECLASSDIALOG_H

#include <QtGui/QDialog>
#include <QPointer>

#include "studentTableModel.h"

class MainController;

namespace Ui {
	class ManageClassDialog;
}

class ManageClassDialog : public QDialog
{
	Q_OBJECT
public:
	ManageClassDialog(MainController *mainController, QWidget *parent = 0);
	~ManageClassDialog();

private:
	Ui::ManageClassDialog *m_ui;
	QPointer <MainController> m_mainController;
	StudentTableModel m_studentTableModel;

};

#endif // MANAGECLASSDIALOG_H
