#ifndef SELECTTEACHERWIDGET_H
#define SELECTTEACHERWIDGET_H

#include <QtGui/QWidget>
#include <QTimer>

#include "teacherTableModel.h"
#include "teacherTableProxyModel.h"

namespace Ui {
	class SelectTeacherWidget;
}

class SelectTeacherWidget : public QWidget
{
	Q_OBJECT
public:
	SelectTeacherWidget(QWidget *parent = 0);
	~SelectTeacherWidget();
	TeacherTableModel *studentTableModel();

private:
	Ui::SelectTeacherWidget *m_ui;

	TeacherTableModel m_teacherTableModel;
	TeacherTableProxyModel m_teacherTableProxyModel;
	QTimer m_searchTimer;

private slots:
	void searchEdited();
	void updateFilter();
};

#endif // SELECTTEACHERWIDGET_H
