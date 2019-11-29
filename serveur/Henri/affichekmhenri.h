#ifndef AFFICHEKMHENRI_H
#define AFFICHEKMHENRI_H
#include "objet_virtuel.h"

class afficheKmHenri : public objet_virtuel
{
public:
    afficheKmHenri(objet_virtuel *parent=nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // AFFICHEKMHENRI_H
