#include "Inna/iconinna.h"
#include <QGraphicsItem>
#include <QtMath>
#include <QPainter>
#include "objet_virtuel.h"
///
/// \file iconinna.cpp
/// \brief Classe IconInna derivée de la classe objet_virtuel
/// \details La classe et utiliser pour ajouter des atributs communes pour les voyants.
/// \param position - parameter de type QPoint(int,int) pour initialiser la position d'un voyant.
/// \param size - parameter de type QSize(int,int) pour initialiser la taille d'un voyant.
/// \param imagePath - parameter de type QString qui correspond au chemin de l'image de voyant.
///
IconInna::IconInna(objet_virtuel *parent) :  objet_virtuel(parent)
{

}

IconInna::IconInna(QPoint p, QSize s, QString pth)
{   value = 0;
    position = p;
    size = s;
    imagePath = pth;
}

QRectF IconInna::boundingRect() const
{
    QRectF rectf(0.0,0.0,1400.0,600.0);
    return rectf;
}

void IconInna::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{ painter->setRenderHints(QPainter::Antialiasing);

  painter->drawPixmap(position.x(),position.y(),size.width(),size.height(),QPixmap(imagePath));

}
/// \bref La fonction **init(QPoint p, QSize s, QString pth)** permet de reinitialiser un voyant.
///
void IconInna::init(QPoint p, QSize s, QString pth)
{
    position = p;
    size = s;
    imagePath = pth;
}


