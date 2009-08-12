#ifndef TUXTYPEMAINWIDGET_H
#define TUXTYPEMAINWIDGET_H

#include <QtGui/QWidget>

#include "studentTableModel.h"

namespace Ui {
	class TuxtypeMainWidget;
}

class SchoolData;
class SelectStudentWidget;

class TuxtypeMainWidget : public QWidget {
	Q_OBJECT
	Q_DISABLE_COPY(TuxtypeMainWidget)
public:
	explicit TuxtypeMainWidget(SchoolData *schoolData, QWidget *parent = 0);
	virtual ~TuxtypeMainWidget();

private:
	Ui::TuxtypeMainWidget *m_ui;
	StudentTableModel m_studentTableModel;
	QPointer<SelectStudentWidget> m_selectStudentWidget;

private slots:
	void setWordListClicked();
};

#endif // TUXTYPEMAINWIDGET_H
