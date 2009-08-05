#include "selectTeacherWidget.h"
#include "ui_selectTeacherWidget.h"

SelectTeacherWidget::SelectTeacherWidget(QWidget *parent)
		: QWidget(parent),
		m_ui(new Ui::SelectTeacherWidget)
{
	m_ui->setupUi(this);

	m_teacherTableProxyModel.setSourceModel(&m_teacherTableModel);
	m_ui->teacherTable->setModel(&m_teacherTableProxyModel);
	connect(m_ui->clearButton, SIGNAL(clicked()), m_ui->searchEdit, SLOT(clear()));
	connect(m_ui->searchEdit, SIGNAL(textEdited(QString)), this, SLOT(searchEdited()));
	connect(&m_searchTimer, SIGNAL(timeout()), this, SLOT(updateFilter()));
}

SelectTeacherWidget::~SelectTeacherWidget()
{
	delete m_ui;
}

TeacherTableModel *SelectTeacherWidget::teacherTableModel()
{
	return &m_teacherTableModel;
}

void SelectTeacherWidget::searchEdited()
{
	m_searchTimer.start(250);
}

void SelectTeacherWidget::updateFilter()
{
	m_teacherTableProxyModel.setFilterRegExp(m_ui->searchEdit->text());
}

