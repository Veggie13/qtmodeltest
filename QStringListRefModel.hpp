#ifndef QSTRINGLISTREFMODEL_HPP
#define QSTRINGLISTREFMODEL_HPP

#include <QAbstractItemView>


class QStringListRefModel : public QAbstractListModel
{
    Q_OBJECT

public:
    QStringListRefModel(QStringList* strings = 0, QObject *parent = 0)
    : QAbstractListModel(parent), m_stringList(strings) {}

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole);
    bool insertRows(int position, int rows, const QModelIndex &index = QModelIndex());
    bool removeRows(int position, int rows, const QModelIndex &index = QModelIndex());

    void setStringList(QStringList* list);

private:
    QStringList* m_stringList;

};

#endif
