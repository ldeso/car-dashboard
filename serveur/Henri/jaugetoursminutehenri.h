#ifndef JAUGETOURSMINUTEHENRI_H
#define JAUGETOURSMINUTEHENRI_H

#include "jaugevirtuel.h"


class jaugeToursMinuteHenri : public jaugeVirtuel
{
public:
    jaugeToursMinuteHenri(jaugeVirtuel *parent=nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    int epesseurTraitToursMinure;
    int tailleTextetoursMinute;
    QString styleTexte;
};

#endif // JAUGETOURSMINUTEHENRI_H
