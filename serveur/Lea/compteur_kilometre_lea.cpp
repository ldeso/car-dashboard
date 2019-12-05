#include "compteur_kilometre_lea.h"
#include <QGraphicsItem>
#include <QObject>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QRectF>
#include <QtMath>
#include <QtDebug>
#include <QPointF>


Compteur_kilometre_lea::Compteur_kilometre_lea(int param_x, int param_y)
{

    x= param_x;
    y=param_y;

//    QFont font3("Seven Segment",10,QFont::Bold);
//    painter->setFont(font3);
//    QRectF affiche_km_totaux (x-50,y+100,90,70);
//    painter->drawText(affiche_km_totaux, Qt::AlignRight ,QString("ODO    %1 km").arg(271963+getValue());

//    QFont font4("Seven Segment",10,QFont::Bold);
//    painter->setFont(font4);
//    QRectF affiche_km_trip_A (x-50,y+130,90,70);
//    painter->drawText(affiche_km_trip_A, Qt::AlignRight ,QString("TRIP A    %1 km").arg(789+getValue());

}

QRectF Compteur_kilometre_lea::boundingRect() const
{
    QRectF rectf(0,0,1000,500);
    return rectf;
}

void Compteur_kilometre_lea::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPen pen(Qt::white);
    painter->setPen(pen);
    QFont font3("Seven Segment",10,QFont::Bold);
    painter->setFont(font3);
    QRectF affiche_km_totaux (x-70,y+100,150,15);
    painter->drawRect(affiche_km_totaux);
    painter->drawText(affiche_km_totaux, Qt::AlignRight ,QString("%1    ").arg(271963+getValue()));
    painter->drawText(affiche_km_totaux, Qt::AlignLeft ,QString("   ODO"));

    QFont font4("Seven Segment",10,QFont::Bold);
    painter->setFont(font4);
    QRectF affiche_km_trip_A (x-70,y+130,150,15);
    painter->drawRect(affiche_km_trip_A);
    painter->drawText(affiche_km_trip_A, Qt::AlignCenter ,QString::number(getValue(),'f',1));
    painter->drawText(affiche_km_trip_A, Qt::AlignLeft ,QString("   TRIP A"));
    painter->drawText(affiche_km_trip_A, Qt::AlignRight ,QString("km    "));
}
