#include "tuxtypeMainWidget.h"
#include "ui_tuxtypeMainWidget.h"

TuxtypeMainWidget::TuxtypeMainWidget(QWidget *parent) :
		QWidget(parent),
		m_ui(new Ui::TuxtypeMainWidget)
{
	m_ui->setupUi(this);
}

TuxtypeMainWidget::~TuxtypeMainWidget()
{
	delete m_ui;
}
