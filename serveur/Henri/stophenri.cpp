#include "stophenri.h"
#include <QDebug>


stopHenri::stopHenri()
{
    value=0;
    cligno=0;
    jt=new jaugeTemperatureHenri();
}

QRectF stopHenri::boundingRect() const
{
    return QRect(-300,-300,600,600);
}

void stopHenri::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*)
{
    if (jt->getValue() > 120)
    {
    QRect carre(-150,-150,300,300);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(QPen(QBrush(QColor("red")) , 88, Qt::SolidLine,Qt::FlatCap));
    painter->setBrush(QBrush(QColor("red")));
    if (cligno==1)
    {
        painter->setPen(QPen(QBrush(QColor("black")) , 88, Qt::SolidLine,Qt::FlatCap));
        painter->setBrush(QBrush(QColor("black")));
    }
    painter->drawArc(carre,231*16,80*16);

    QRect carre2(-66,81,134,50);
    painter->setPen(QPen(QBrush(QColor("red")) , 1, Qt::SolidLine,Qt::FlatCap));
    if (cligno==1)
        painter->setPen(QPen(QBrush(QColor("black")) , 1, Qt::SolidLine,Qt::FlatCap));
    painter->drawRect(carre2);

    painter->setPen(QPen(QBrush(QColor("black")) , 80, Qt::SolidLine,Qt::FlatCap));
    if (cligno==1)
        painter->setPen(QPen(QBrush(QColor("red")) , 80, Qt::SolidLine,Qt::FlatCap));
    painter->setFont(QFont("unroob",50));
    painter->drawText(-86,160,"STOP");
    MAJ();
    }


}

void stopHenri::resizeEvent()
{
    setValue(0);
    cligno=0;
    update();
}

void stopHenri::activation()
{
//    if (jt->getValue()>120)
//        this->setValue(1);
}

void stopHenri::MAJ()
{
    cligno=!cligno;
    QTest::qWait(800);
    update();
}
