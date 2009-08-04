#ifndef TEACHERTABLEPROXYMODEL_H
#define TEACHERTABLEPROXYMODEL_H

#include <QSortFilterProxyModel>

class TeacherTableProxyModel : public QSortFilterProxyModel
{
	Q_OBJECT
public:
	TeacherTableProxyModel(QObject *parent = 0);

	bool lessThan(const QModelIndex &left, const QModelIndex &right) const;
	bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const;

};

#endif // TEACHERTABLEPROXYMODEL_H
