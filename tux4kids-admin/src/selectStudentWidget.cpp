#include "selectStudentWidget.h"
#include "ui_selectStudentWidget.h"

SelectStudentWidget::SelectStudentWidget(QWidget *parent) :
		QWidget(parent),
		m_ui(new Ui::SelectStudentWidget)
{
	m_ui->setupUi(this);

	m_studentTableProxyModel.setSourceModel(&m_studentTableModel);
	m_ui->studentTable->setModel(&m_studentTableProxyModel);

	m_ui->filterKeyCombo->addItem(tr("Everything"),
				      StudentTableProxyModel::Everything);
	m_ui->filterKeyCombo->addItem(tr("First name"),
				      StudentTableProxyModel::FirstName);
	m_ui->filterKeyCombo->addItem(tr("Last name"),
				      StudentTableProxyModel::LastName);
	m_ui->filterKeyCombo->addItem(tr("Class"),
				      StudentTableProxyModel::ClassName);

	connect(m_ui->clearButton, SIGNAL(clicked()), m_ui->searchEdit, SLOT(clear()));
	connect(m_ui->searchEdit, SIGNAL(textEdited(QString)), this, SLOT(searchEdited()));
	connect(m_ui->filterKeyCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(filterKeyColumnChanged(int)));
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

void SelectStudentWidget::filterKeyColumnChanged(int index)
{
	m_studentTableProxyModel.setFilterKeyColumn(m_ui->filterKeyCombo->itemData(index).toInt());
}

