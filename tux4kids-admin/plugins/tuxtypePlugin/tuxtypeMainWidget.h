#ifndef TUXTYPEMAINWIDGET_H
#define TUXTYPEMAINWIDGET_H

#include <QtGui/QWidget>

namespace Ui {
	class TuxtypeMainWidget;
}

class TuxtypeMainWidget : public QWidget {
	Q_OBJECT
	Q_DISABLE_COPY(TuxtypeMainWidget)
public:
	explicit TuxtypeMainWidget(QWidget *parent = 0);
	virtual ~TuxtypeMainWidget();

private:

	Ui::TuxtypeMainWidget *m_ui;
};

#endif // TUXTYPEMAINWIDGET_H
