#include "loto_dahsboard.h"

loto_dahsboard::loto_dahsboard(QObject *parent)
    : QAbstractItemModel(parent)
{
}

QVariant loto_dahsboard::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex loto_dahsboard::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex loto_dahsboard::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int loto_dahsboard::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int loto_dahsboard::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant loto_dahsboard::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
