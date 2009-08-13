#include "studentTableDelegate.h"
#include "studentTableModel.h"

#include <QComboBox>
#include <QDebug>

StudentTableDelegate::StudentTableDelegate(QObject *parent)
		: QItemDelegate(parent)
{
}

QWidget *StudentTableDelegate::createEditor(QWidget *parent,
					    const QStyleOptionViewItem &option,
					    const QModelIndex &index) const
{
	QComboBox *editor = new QComboBox(parent);
	return editor;
}

void StudentTableDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
	QString data = index.data(Qt::DisplayRole).toString();
	QComboBox *comboBox = static_cast<QComboBox *>(editor);
	if (comboBox != 0) {
		comboBox->addItem(data);
		comboBox->addItem("Computer 1");
		comboBox->addItem("Computer 2");
	}
}

void StudentTableDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
					const QModelIndex &index) const
{
	QComboBox *comboBox = static_cast<QComboBox *>(editor);
	if (comboBox != 0) {
		qDebug() << "data set to" << comboBox->currentText();
	}
}

void StudentTableDelegate::updateEditorGeometry(QWidget *editor,
						const QStyleOptionViewItem &option, const QModelIndex & index) const
{
	editor->setGeometry(option.rect);
}
