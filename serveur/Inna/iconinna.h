#ifndef ICONINNA_H
#define ICONINNA_H
#include <QGraphicsItem>
#include "objet_virtuel.h"
#include <QRectF>
#include <QFont>

class IconInna : public objet_virtuel
{
public:
    IconInna (objet_virtuel *parent = nullptr);
    IconInna (QPoint p, QSize s, QString pth);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QString imagePath;
    QPoint position;
    QSize size;
    void init(QPoint p, QSize s, QString pth);
    int val;

};

#endif // ICONINNA_H
