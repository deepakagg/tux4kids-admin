#include "tuxtypeMainWidget.h"
#include "ui_tuxtypeMainWidget.h"
#include "studentTableModel.h"
#include "selectStudentWidget.h"
#include "editWordListDialog.h"

TuxtypeMainWidget::TuxtypeMainWidget(SchoolData *schoolData, QWidget *parent) :
		QWidget(parent),
		m_ui(new Ui::TuxtypeMainWidget)
{
	m_ui->setupUi(this);

	m_studentTableModel.setSchoolData(schoolData);
	m_selectStudentWidget = new SelectStudentWidget(this);
	m_ui->verticalLayout->insertWidget(0, m_selectStudentWidget);
	m_selectStudentWidget->setStudentTableModel(&m_studentTableModel);

	connect(m_ui->setWordListButton, SIGNAL(clicked()), this, SLOT(setWordListClicked()));
}

TuxtypeMainWidget::~TuxtypeMainWidget()
{
	delete m_ui;
}

void TuxtypeMainWidget::setWordListClicked()
{
	EditWordListDialog editWordList;
	editWordList.exec();
}

