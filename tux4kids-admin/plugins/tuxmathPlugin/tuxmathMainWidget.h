#ifndef TUXMATHMAINWIDGET_H
#define TUXMATHMAINWIDGET_H

#include <QtGui/QWidget>
#include <QPointer>

#include "studentTableModel.h"

namespace Ui {
	class TuxmathMainWidget;
}

class SchoolData;
class SelectStudentWidget;

class TuxmathMainWidget : public QWidget {
	Q_OBJECT
	Q_DISABLE_COPY(TuxmathMainWidget)
public:
	explicit TuxmathMainWidget(SchoolData *schoolData, QWidget *parent = 0);
	virtual ~TuxmathMainWidget();

private:
	Ui::TuxmathMainWidget *m_ui;
	StudentTableModel m_studentTableModel;
	QPointer<SelectStudentWidget> m_selectStudentWidget;

};

#endif // TUXMATHMAINWIDGET_H
