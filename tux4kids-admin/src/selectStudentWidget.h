#ifndef SELECTSTUDENTWIDGET_H
#define SELECTSTUDENTWIDGET_H

#include <QtGui/QWidget>
#include <QTimer>

#include "studentTableModel.h"
#include "studentTableProxyModel.h"

class QTableView;

namespace Ui {
	class SelectStudentWidget;
}

class SelectStudentWidget : public QWidget
{
	Q_OBJECT
public:
	SelectStudentWidget(QWidget *parent = 0);
	~SelectStudentWidget();

	void setStudentTableModel(StudentTableModel *studentTableModel);
	QTableView *studentTable();

private:
	Ui::SelectStudentWidget *m_ui;

	StudentTableModel m_studentTableModel;
	StudentTableProxyModel m_studentTableProxyModel;
	QTimer m_searchTimer;

private slots:
	void searchEdited();
	void updateFilter();
	void filterKeyColumnChanged(int index);

};

#endif // SELECTSTUDENTWIDGET_H
