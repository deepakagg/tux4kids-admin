#ifndef TUXMATHMAINWIDGET_H
#define TUXMATHMAINWIDGET_H

#include <QtGui/QWidget>

namespace Ui {
	class TuxmathMainWidget;
}

class TuxmathMainWidget : public QWidget {
	Q_OBJECT
	Q_DISABLE_COPY(TuxmathMainWidget)
public:
	explicit TuxmathMainWidget(QWidget *parent = 0);
	virtual ~TuxmathMainWidget();

private:

	Ui::TuxmathMainWidget *m_ui;
};

#endif // TUXMATHMAINWIDGET_H
