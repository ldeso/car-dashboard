#ifndef CLIGNOTANT_H
#define CLIGNOTANT_H
#include "Inna/iconinna.h"
#include <QRectF>
#include <QFont>


class clignotantInna : public IconInna
{
public:
    clignotantInna(IconInna *parent = nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int cligno;
    int mode;
    void MAJ();

};

#endif // CLIGNOTANT_H
