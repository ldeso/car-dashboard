#ifndef JAUGETOURSMINUTEHENRI_H
#define JAUGETOURSMINUTEHENRI_H

#include "objet_virtuel.h"


class jaugeToursMinuteHenri : public objet_virtuel
{
public:
    jaugeToursMinuteHenri(objet_virtuel *parent=nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    int epesseurTraitToursMinure;
    int tailleTextetoursMinute;
    QString styleTexte;
};

#endif // JAUGETOURSMINUTEHENRI_H
