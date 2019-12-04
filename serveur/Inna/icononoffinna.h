#ifndef ICONONOFF_H
#define ICONONOFF_H
#include "Inna/iconinna.h"
#include <QRectF>
#include <QFont>

class iconOnOffInna : public IconInna
{
public:
    iconOnOffInna(IconInna *parent = nullptr);
    iconOnOffInna (QPoint p, QSize s, QString pth, double Z);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // ICONONOFF_H
