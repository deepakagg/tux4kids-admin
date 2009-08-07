#include "selectClassWidget.h"
#include "ui_selectClassWidget.h"

SelectClassWidget::SelectClassWidget(QWidget *parent)
		: QWidget(parent),
		m_ui(new Ui::SelectClassWidget)
{
	m_ui->setupUi(this);

	m_ui->classTable->setModel(&m_classTableProxyModel);
	connect(m_ui->clearButton, SIGNAL(clicked()), m_ui->searchEdit, SLOT(clear()));
	connect(m_ui->searchEdit, SIGNAL(textEdited(QString)), this, SLOT(searchEdited()));
	connect(&m_searchTimer, SIGNAL(timeout()), this, SLOT(updateFilter()));
}

SelectClassWidget::~SelectClassWidget()
{
	delete m_ui;
}

void SelectClassWidget::setClassTableModel(ClassTableModel *classTableModel)
{
	m_classTableProxyModel.setSourceModel(classTableModel);
}

QTableView *SelectClassWidget::classTable()
{
	return m_ui->classTable;
}

void SelectClassWidget::searchEdited()
{
	m_searchTimer.start(250);
}

void SelectClassWidget::updateFilter()
{
	m_classTableProxyModel.setFilterRegExp(m_ui->searchEdit->text());
}

