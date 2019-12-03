#ifndef LOTO_DAHSBOARD_H
#define LOTO_DAHSBOARD_H

#include <QAbstractItemModel>

class loto_dahsboard : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit loto_dahsboard(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
};

#endif // LOTO_DAHSBOARD_H
