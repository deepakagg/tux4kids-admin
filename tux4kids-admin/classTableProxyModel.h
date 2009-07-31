#ifndef CLASSTABLEPROXYMODEL_H
#define CLASSTABLEPROXYMODEL_H

#include <QSortFilterProxyModel>

class ClassTableProxyModel : public QSortFilterProxyModel
{
	Q_OBJECT
public:
	ClassTableProxyModel(QObject *parent = 0);

	bool lessThan(const QModelIndex &left, const QModelIndex &right) const;
};

#endif // CLASSTABLEPROXYMODEL_H
