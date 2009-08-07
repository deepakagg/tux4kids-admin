#ifndef SELECTCLASSWIDGET_H
#define SELECTCLASSWIDGET_H

#include <QtGui/QWidget>
#include <QTimer>

#include "classTableModel.h"
#include "classTableProxyModel.h"

namespace Ui {
	class SelectClassWidget;
}

class QTableView;

class SelectClassWidget : public QWidget
{
	Q_OBJECT
public:
	SelectClassWidget(QWidget *parent = 0);
	~SelectClassWidget();

	void setClassTableModel(ClassTableModel *classTableModel);
	QTableView *classTable();
	QModelIndex selectedClassIndex();

private:
	Ui::SelectClassWidget *m_ui;

	ClassTableProxyModel m_classTableProxyModel;
	QTimer m_searchTimer;

private slots:
	void searchEdited();
	void updateFilter();
};

#endif // SELECTCLASSWIDGET_H
