#include "tuxmathMainWidget.h"
#include "ui_tuxmathMainWidget.h"

#include "schoolData.h"
#include "selectStudentWidget.h"

TuxmathMainWidget::TuxmathMainWidget(SchoolData *schoolData, QWidget *parent) :
		QWidget(parent),
		m_ui(new Ui::TuxmathMainWidget)
{
	m_ui->setupUi(this);


	m_studentTableModel.setSchoolData(schoolData);
	m_selectStudentWidget = new SelectStudentWidget(this);
	m_ui->verticalLayout->insertWidget(0, m_selectStudentWidget);
	m_selectStudentWidget->setStudentTableModel(&m_studentTableModel);
}

TuxmathMainWidget::~TuxmathMainWidget()
{
	delete m_ui;
}
