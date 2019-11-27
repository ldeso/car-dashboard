#include "jaugeclignotant.h"
#include <QDebug>


jaugeClignotant::jaugeClignotant()
{
    valeur=0;
    cligno=0;
}

QRectF jaugeClignotant::boundingRect() const
{
    return QRect(-800,-450,1600,900);
}

void jaugeClignotant::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
//    int l=241;
//    QRect carre1(-l,-l,2*l,2*l);
//    painter->setRenderHint(QPainter::Antialiasing);
//    painter->setPen(QPen(QBrush(QColor(250,150,0,255)) , 15, Qt::SolidLine,Qt::FlatCap));
//    if(valeur < 40 & cligno==1)
//        painter->drawArc(carre1,-89*16,valeur*16-1);
//    if(valeur >= 40 & cligno==1)
//        painter->drawArc(carre1,(-89+valeur-40)*16,(79-valeur)*16);
//    if(valeur < 40 & cligno==-1)
//        painter->drawArc(carre1,-89*16,-valeur*16-1);
//    if(valeur >= 40 & cligno==-1)
//        painter->drawArc(carre1,(-89-valeur+40)*16,-(79-valeur)*16);

    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(QPen(QBrush(QColor(250,200,0,255)) , 1, Qt::SolidLine,Qt::FlatCap));
    painter->setBrush(QBrush(QColor(250,200,0,255)));
    float pi=3.1415;
    if (cligno !=0)
    {
        for (int j=0;j<valeur;j+=1)
        {
            float i=1.65*j*pi/60;
            QVector<QPoint> points;
            points.append(QPoint(cos(cligno*i-pi/2)*227+2,-sin(cligno*i-pi/2)*227));
            points.append(QPoint((cos(cligno*i+cligno*1.65*pi/60-pi/2))*(227+15)+2,-sin(cligno*i+cligno*1.65*pi/60-pi/2)*(227+15)));
            points.append(QPoint(cos(cligno*i-pi/2)*(227+30)+2,-sin(cligno*i-pi/2)*(227+30)));
            QPolygon poly(points);
            painter->drawPolygon(poly);
        }
    }

}
