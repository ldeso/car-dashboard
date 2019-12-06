#include "Inna/infowindowinna.h"
#include <QGraphicsItem>
#include <QtMath>
#include <QPainter>
///
/// \file infowindowinna.cpp
/// \brief Classe InfoWindowInna derivée de la classe QGraphicsItem
/// \details La classe est utiliser pour créer un tableau d'information
/// \param r - rayon de l'arche encadrante.
///
InfoWindowInna::InfoWindowInna(QGraphicsItem *parent) :  QGraphicsItem(parent)
{
    r = 150;
}

QRectF InfoWindowInna::boundingRect() const
{
    QRectF rectf(0.0,0.0,1400.0,600.0);
    return rectf;
}
///
/// \brief InfoWindowInna::paint
/// \param painter
/// \details La fonction crée un object static qui sert comme un fond pour des voyants et des messages d'info.
///
void InfoWindowInna::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
   painter->setRenderHint(QPainter::Antialiasing);
   painter->setBrush(QBrush("#0a0f0f",Qt::SolidPattern));
   painter->drawEllipse(QRectF(xc-r,yc-r,r*2,r*2));
   QRadialGradient radialGradl(QPointF(xc, yc), r+20);
   radialGradl.setColorAt(0, Qt::transparent);
   radialGradl.setColorAt(0.8, "#f2f2f2");
   radialGradl.setColorAt(0.9, "#333333");
   radialGradl.setColorAt(1, "#f2f2f2");
   painter->setPen(QPen(QBrush(radialGradl),4,Qt::SolidLine,Qt::FlatCap));
   painter->drawArc(QRectF(xc-r,yc-r,r*2,r*2),205*16,298*16);

}
