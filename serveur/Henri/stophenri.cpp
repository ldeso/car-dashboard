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
//    QRect carre(-150,-150,300,300);
//    painter->setRenderHint(QPainter::Antialiasing);
//    painter->setPen(QPen(QBrush(QColor("red")) , 88, Qt::SolidLine,Qt::FlatCap));
//    painter->drawArc(carre,231*16,80*16);

//    QRect carre2(-100,0,200,100);
//    painter->drawRect(carre2);
}
