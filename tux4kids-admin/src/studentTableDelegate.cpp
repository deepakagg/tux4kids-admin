#include "studentTableDelegate.h"
#include "studentTableModel.h"
#include "studentTableProxyModel.h"

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
		const StudentTableModel *model = qobject_cast<const StudentTableModel *>( index.model());
		if (model != 0) {
			int computerCount = model->computerCount();
			comboBox->addItem(data);
			for (int i = 1; i <= computerCount; ++i) {
				comboBox->addItem(tr("Computer %1").arg(i));
			}
		} else {
			const StudentTableProxyModel *proxyModel = qobject_cast<const StudentTableProxyModel *>(index.model());
			const StudentTableModel *model = qobject_cast<const StudentTableModel *> (proxyModel->sourceModel());
			if (model != 0) {
				int computerCount = model->computerCount();
				comboBox->addItem(data);
				for (int i = 1; i <= computerCount; ++i) {
					comboBox->addItem(tr("Computer %1").arg(i));
				}
			}
		}
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
