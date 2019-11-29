#ifndef CADRANTHENRI_H
#define CADRANTHENRI_H

#include "objet_virtuel.h"

class cadrantHenri : public objet_virtuel
{
public:
    cadrantHenri(objet_virtuel *parent=nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

//    QString styleTexte;

    int epesseurTraitVitesse;
    int tailleTexteVitesse;
    int valeurMaxNombreCompteur;

};

#endif // CADRANTHENRI_H
