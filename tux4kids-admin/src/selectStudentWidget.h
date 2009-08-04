#ifndef SELECTSTUDENTWIDGET_H
#define SELECTSTUDENTWIDGET_H

#include <QtGui/QWidget>
#include <QTimer>

#include "studentTableModel.h"
#include "studentTableProxyModel.h"

namespace Ui {
	class SelectStudentWidget;
}

class SelectStudentWidget : public QWidget
{
	Q_OBJECT
public:
	SelectStudentWidget(QWidget *parent = 0);
	~SelectStudentWidget();

	StudentTableModel *studentTableModel();

private:
	Ui::SelectStudentWidget *m_ui;

	StudentTableModel m_studentTableModel;
	StudentTableProxyModel m_studentTableProxyModel;
	QTimer m_searchTimer;

private slots:
	void searchEdited();
	void updateFilter();

};

#endif // SELECTSTUDENTWIDGET_H
