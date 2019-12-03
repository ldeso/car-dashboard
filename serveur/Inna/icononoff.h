#ifndef ICONONOFF_H
#define ICONONOFF_H
#include "Inna/iconinna.h"
#include <QRectF>
#include <QFont>

class iconOnOff : public IconInna
{
public:
    iconOnOff(IconInna *parent = nullptr);
    iconOnOff (QPoint p, QSize s, QString pth, double Z);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // ICONONOFF_H
