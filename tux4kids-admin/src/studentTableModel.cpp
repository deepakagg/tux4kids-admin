#include "studentTableModel.h"
#include "schoolData.h"

StudentTableModel::StudentTableModel(SchoolData *schoolData, QObject *parent)
		: QAbstractTableModel(parent),
		m_schoolData(schoolData)
{
}

StudentTableModel::~StudentTableModel()
{
}
