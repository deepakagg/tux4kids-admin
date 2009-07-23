#ifndef CLASSTABLEMODEL_H
#define CLASSTABLEMODEL_H

#include <QAbstractTableModel>

class ClassTableModel : public QAbstractTableModel
{
	Q_OBJECT
public:
	ClassTableModel(QObject *parent = 0);
};

#endif // CLASSTABLEMODEL_H
