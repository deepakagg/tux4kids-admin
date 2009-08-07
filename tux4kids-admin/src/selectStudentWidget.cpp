#include "selectStudentWidget.h"
#include "ui_selectStudentWidget.h"

SelectStudentWidget::SelectStudentWidget(QWidget *parent) :
		QWidget(parent),
		m_ui(new Ui::SelectStudentWidget)
{
	m_ui->setupUi(this);

	m_studentTableProxyModel.setSourceModel(&m_studentTableModel);
	m_ui->studentTable->setModel(&m_studentTableProxyModel);
	connect(m_ui->clearButton, SIGNAL(clicked()), m_ui->searchEdit, SLOT(clear()));
	connect(m_ui->searchEdit, SIGNAL(textEdited(QString)), this, SLOT(searchEdited()));
	connect(&m_searchTimer, SIGNAL(timeout()), this, SLOT(updateFilter()));
}

SelectStudentWidget::~SelectStudentWidget()
{
	delete m_ui;
}

void SelectStudentWidget::setStudentTableModel(StudentTableModel *studentTableModel)
{
	m_studentTableProxyModel.setSourceModel(studentTableModel);
}

void SelectStudentWidget::searchEdited()
{
	m_searchTimer.start(250);
}

void SelectStudentWidget::updateFilter()
{
	m_studentTableProxyModel.setFilterRegExp(m_ui->searchEdit->text());
}

