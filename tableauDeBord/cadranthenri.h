#ifndef CADRANTHENRI_H
#define CADRANTHENRI_H

#include "cadrantvirtuel.h"

class cadrantHenri : public cadrantVirtuel
{
public:
    cadrantHenri(cadrantVirtuel *parent=nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QString styleTexte;

    int epesseurTraitVitesse;
    int tailleTexteVitesse;

    int toursMinute;
    int toursMinuteMax;
    int epesseurTraitToursMinure;
    int tailleTextetoursMinute;
};

#endif // CADRANTHENRI_H
