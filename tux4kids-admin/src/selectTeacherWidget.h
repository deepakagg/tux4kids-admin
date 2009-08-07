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
	void setTeacherTableModel(TeacherTableModel *teacherTableModel);

private:
	Ui::SelectTeacherWidget *m_ui;

	TeacherTableProxyModel m_teacherTableProxyModel;
	QTimer m_searchTimer;

private slots:
	void searchEdited();
	void updateFilter();
};

#endif // SELECTTEACHERWIDGET_H
