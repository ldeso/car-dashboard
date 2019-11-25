#ifndef JAUGEVIRTUEL_H
#define JAUGEVIRTUEL_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QtMath>

class jaugeVirtuel : public QGraphicsItem
{
public:
    jaugeVirtuel(QGraphicsItem *parent=nullptr);
};

#endif // JAUGEVIRTUEL_H
