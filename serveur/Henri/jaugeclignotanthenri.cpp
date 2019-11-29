#include "jaugeclignotanthenri.h"
#include <QDebug>


jaugeClignotantHenri::jaugeClignotantHenri()
{
    value=0;
    cligno=0;
}

QRectF jaugeClignotantHenri::boundingRect() const
{
    return QRect(-700,-380,1400,780);
}

void jaugeClignotantHenri::MAJ()
{
    this->cligno+=1;
    if(this->cligno == 9)
        this->cligno=0;
    QTest::qWait(80);
    update();
}

void jaugeClignotantHenri::MAJ2()
{
    this->cligno+=1;
    if(this->cligno == 2)
        this->cligno=0;
    QTest::qWait(500);
    update();
}

void jaugeClignotantHenri::paint(QPainter *painter, const QStyleOptionGraphicsItem* , QWidget* )
{
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(QPen(QBrush(QColor(255,200,0,125)) , 2, Qt::SolidLine,Qt::FlatCap));
    painter->setBrush(QBrush(QColor(255,200,0,255)));
    float pi=3.14159265;
    if (getValue() ==2)
    {
        int l=241;
        QRect carre1(-l,-l,2*l,2*l);
        if (cligno == 0)
        {
            painter->setPen(QPen(QBrush("black") , 28, Qt::SolidLine,Qt::FlatCap));
             painter->drawArc(carre1,-128*16,78*16);
        }

        if (cligno == 1)
        {
            for (int i=28;i>23;i--)
            {
            painter->setPen(QPen(QBrush(QColor(255,200,0,50)) , 28, Qt::SolidLine,Qt::FlatCap));
            painter->drawArc(carre1,-128*16,78*16);
            painter->setPen(QPen(QBrush(QColor(255,200,0,50)) , 24, Qt::SolidLine,Qt::FlatCap));
            painter->drawArc(carre1,-128*16+8,78*16-16);
            painter->setPen(QPen(QBrush(QColor(255,200,0,50)) , 20, Qt::SolidLine,Qt::FlatCap));
            painter->drawArc(carre1,-128*16+16,78*16-32);
            }
        }
        MAJ2();
    }

    if ( (getValue() == 1) | (getValue()== -1) )
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
