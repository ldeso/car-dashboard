#include "stophenri.h"

stopHenri::stopHenri()
{

}

QRectF stopHenri::boundingRect() const
{
    return QRect(-300,-300,600,600);
}

void stopHenri::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*)
{
    if (getValue()==1)
    {
    QRect carre(-150,-150,300,300);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(QPen(QBrush(QColor("red")) , 88, Qt::SolidLine,Qt::FlatCap));
    painter->drawArc(carre,231*16,80*16);

    painter->setPen(QPen(QBrush(QColor("red")) , 1, Qt::SolidLine,Qt::FlatCap));
    painter->setBrush(QBrush(QColor("red")));
    QRect carre2(-66,81,134,50);
    painter->drawRect(carre2);
    }
}
