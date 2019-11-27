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

void jaugeClignotant::MAJ()
{
    this->cligno+=1;
    if(this->cligno == 9)
        this->cligno=0;
    QTest::qWait(50);
    update();
}

void jaugeClignotant::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(QPen(QBrush(QColor(250,200,0,255)) , 1, Qt::SolidLine,Qt::FlatCap));
    painter->setBrush(QBrush(QColor(250,200,0,255)));
    float pi=3.14159265;
    if (getValue() !=0)

    {

        for (int j=0;j<cligno;j+=1)
        {
            float i=1.65*j*pi/60;
            QVector<QPoint> points;
            points.append(QPoint(cos(getValue()*i-pi/2)*227+2,-sin(getValue()*i-pi/2)*227));
            points.append(QPoint((cos(getValue()*i+getValue()*1.65*pi/60-pi/2))*(227+15)+2,-sin(getValue()*i+getValue()*1.65*pi/60-pi/2)*(227+15)));
            points.append(QPoint(cos(getValue()*i-pi/2)*(227+30)+2,-sin(getValue()*i-pi/2)*(227+30)));
            QPolygon poly(points);
            painter->drawPolygon(poly);

        }
    MAJ();
    }
}
