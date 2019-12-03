#ifndef PRND_H
#define PRND_H
#include "Inna/iconinna.h"
#include <QRectF>
#include <QFont>

class PRND_Inna : public IconInna
{
public:
    PRND_Inna(IconInna *parent = nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // PRND_H
