#include "tuxmathMainWidget.h"
#include "ui_tuxmathMainWidget.h"

TuxmathMainWidget::TuxmathMainWidget(QWidget *parent) :
		QWidget(parent),
		m_ui(new Ui::TuxmathMainWidget)
{
	m_ui->setupUi(this);
}

TuxmathMainWidget::~TuxmathMainWidget()
{
	delete m_ui;
}
