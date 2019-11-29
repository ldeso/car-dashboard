#include "hugo_ecran.h"
#include <QTime>

hugo_ecran::hugo_ecran()
{
    value=0;
}

QRectF hugo_ecran::boundingRect() const
{
    qreal penWidth = 5;
    return QRectF(-10 - penWidth / 2, -10 - penWidth / 2, 20 + penWidth, 20 + penWidth);
}

void hugo_ecran::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*)
{
    painter->setPen(QPen(QColor(0,0,0,0) , 1, Qt::SolidLine,Qt::FlatCap));
    painter->setBrush(QColor(0,128,255,15));
    painter->drawRect(-45,25,90,40);
    QRadialGradient radialGrad(QPointF(0, 45), 50);
    radialGrad.setColorAt(0, QColor(0,204,255));
    radialGrad.setColorAt(1, QColor(0, 128, 255));
    painter->setPen(QPen(QColor(0,204,255) , 1, Qt::SolidLine,Qt::FlatCap));
    painter->setBrush(radialGrad);
    painter->drawRect(-40,30,80,30);
    painter->setPen(QPen(Qt::black, 1, Qt::SolidLine,Qt::FlatCap));
    painter->setFont(QFont("Arial", 5, -1,false));
    painter->drawText(-38,40,"TIME");
    painter->drawText(-38,55,"TRIP");


    QTime time=QTime::currentTime();
    time.currentTime();
    painter->setFont(QFont("Arial", 9, -1,false));
    painter->drawText(0,45,time.toString("hh.mm")); ///< Conversion pour avoir l'affichage sous forme heure.minutes
    painter->drawText(0,60, QString::number(getValue()));


    painter->setPen(QPen(QColor( 26, 13, 0), 1, Qt::SolidLine,Qt::FlatCap));
    painter->setBrush(QColor( 26,13,0));
}
