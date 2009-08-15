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
	int computerNum = index.data(Qt::UserRole).toInt();
	QComboBox *comboBox = static_cast<QComboBox *>(editor);
	if (comboBox != 0) {
		const StudentTableModel *model = qobject_cast<const StudentTableModel *>( index.model());
		if (model != 0) {
			int computerCount = model->computerCount();
			if (computerNum > 0) {
				comboBox->addItem(tr("Computer %1").arg(computerNum), computerNum);
			}
			comboBox->addItem(tr("None"), -1);
			for (int i = 1; i <= computerCount; ++i) {
				if (i != computerNum) {
					comboBox->addItem(tr("Computer %1").arg(i), i);
				}
			}
		} else {
			const StudentTableProxyModel *proxyModel = qobject_cast<const StudentTableProxyModel *>(index.model());
			const StudentTableModel *model = qobject_cast<const StudentTableModel *> (proxyModel->sourceModel());
			if (model != 0) {
				int computerCount = model->computerCount();
				if (computerNum > 0) {
				comboBox->addItem(tr("Computer %1").arg(computerNum), computerNum);
				}
				comboBox->addItem(tr("None"), -1);
				for (int i = 1; i <= computerCount; ++i) {
					if (i != computerNum) {
						comboBox->addItem(tr("Computer %1").arg(i), i);
					}
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
		model->setData(index, comboBox->itemData(comboBox->currentIndex(), Qt::UserRole), Qt::UserRole);
	}
}

void StudentTableDelegate::updateEditorGeometry(QWidget *editor,
						const QStyleOptionViewItem &option, const QModelIndex & index) const
{
	editor->setGeometry(option.rect);
}
