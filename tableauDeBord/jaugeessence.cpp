#include "jaugeessence.h"


jaugeEssence::jaugeEssence(jaugeVirtuel *parent):jaugeVirtuel (parent)
{
    essence=100;
}
QRectF jaugeEssence::boundingRect() const
{
    return QRect(-800,-450,1600,900);
}

void jaugeEssence::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
//début jauge à essence
    QRect carre(-280,-280,560,560);

    painter->setPen(QPen(QBrush(QColor(250-essence*2.5,essence*2.5,0,80)) , 26, Qt::SolidLine,Qt::FlatCap));
    painter->drawArc(carre,231*16,100*16*0.8);//le fond de transparence 80

    painter->setPen(QPen(QBrush(QColor(250-essence*2.5,essence*2.5,0,255)) , 30, Qt::SolidLine,Qt::FlatCap));
    painter->drawArc(carre,231*16,essence*16*0.8);//l'essence réel de transparence 255 (aucune transparence)

//fin jauge essece
}
