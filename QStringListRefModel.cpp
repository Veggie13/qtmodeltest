#include "QStringListRefModel.hpp"


int QStringListRefModel::rowCount(const QModelIndex &parent) const
{
    if (!m_stringList)
        return -1;

    return m_stringList->count();
}

QVariant QStringListRefModel::data(const QModelIndex &index, int role) const
{
    if (!m_stringList)
        return QVariant();

    if (!index.isValid())
        return QVariant();

    if (index.row() >= m_stringList->size())
        return QVariant();

    if (role == Qt::DisplayRole)
        return m_stringList->at(index.row());
    else
        return QVariant();
}

QVariant QStringListRefModel::headerData(int section, Qt::Orientation orientation,
                                         int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal)
        return QString("Column %1").arg(section);
    else
        return QString("Row %1").arg(section);
}

Qt::ItemFlags QStringListRefModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

bool QStringListRefModel::setData(const QModelIndex &index,
                                  const QVariant &value, int role)
{
    if (!m_stringList)
        return false;

    if (index.isValid() && role == Qt::EditRole)
    {
        m_stringList->replace(index.row(), value.toString());
        emit dataChanged(index, index);
        return true;
    }

    return false;
}

bool QStringListRefModel::insertRows(int position, int rows, const QModelIndex &parent)
{
    if (!m_stringList)
        return false;

    beginInsertRows(QModelIndex(), position, position+rows-1);

    for (int row = 0; row < rows; ++row)
    {
        m_stringList->insert(position, "");
    }

    endInsertRows();
    return true;
}

bool QStringListRefModel::removeRows(int position, int rows, const QModelIndex &parent)
{
    if (!m_stringList)
        return false;

    beginRemoveRows(QModelIndex(), position, position+rows-1);

    for (int row = 0; row < rows; ++row)
    {
        m_stringList->removeAt(position);
    }

    endRemoveRows();
    return true;
}

void QStringListRefModel::setStringList(QStringList* list)
{
    m_stringList = list;
    reset();
}
