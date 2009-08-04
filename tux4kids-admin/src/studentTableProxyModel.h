#ifndef STUDENTTABLEPROXYMODEL_H
#define STUDENTTABLEPROXYMODEL_H

#include <QSortFilterProxyModel>

class StudentTableProxyModel : public QSortFilterProxyModel
{
	Q_OBJECT
public:
	StudentTableProxyModel(QObject *parent = 0);

	bool lessThan(const QModelIndex &left, const QModelIndex &right) const;
	bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const;
};

#endif // STUDENTTABLEPROXYMODEL_H
