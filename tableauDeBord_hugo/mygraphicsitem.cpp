#include "mygraphicsitem.h"
#include <QtMath>
#include <QDebug>
#define pi 3.14159265

MyGraphicsitem::MyGraphicsitem()
{
}



QRectF MyGraphicsitem::boundingRect() const
{
    qreal penWidth = 5;
    return QRectF(-10 - penWidth / 2, -10 - penWidth / 2, 20 + penWidth, 20 + penWidth);
}

void MyGraphicsitem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //Création du fond noir
    QBrush black_brush(Qt::black);
    painter->setBrush(black_brush);
    painter->drawRect(-450,-300,900,600);


    //Arc de cercle extérieur
    QRect carre(-100,-100,200,200);
    painter->setPen(QPen( QColor(51,102,153) ,5, Qt::SolidLine,Qt::FlatCap));
    painter->drawChord(carre,-60*16,300*16);



}
