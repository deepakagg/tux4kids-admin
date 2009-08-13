#ifndef STUDENTTABLEDELEGATE_H
#define STUDENTTABLEDELEGATE_H

#include <QItemDelegate>

class StudentTableDelegate : public QItemDelegate
{
	Q_OBJECT
public:
	StudentTableDelegate(QObject *parent = 0);

	QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
			      const QModelIndex &index) const;
	void setEditorData(QWidget *editor, const QModelIndex &index) const;
	void setModelData(QWidget *editor, QAbstractItemModel *model,
			  const QModelIndex &index) const;
	void updateEditorGeometry(QWidget *editor,
				  const QStyleOptionViewItem &option, const
				  QModelIndex &index) const;
};

#endif // STUDENTTABLEDELEGATE_H
