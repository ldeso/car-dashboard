#include "jaugeessencehenri.h"


jaugeEssenceHenri::jaugeEssenceHenri(jaugeVirtuel *parent):jaugeVirtuel (parent)
{
    valeur=100;
}
QRectF jaugeEssenceHenri::boundingRect() const
{
    return QRect(-800,-450,1600,900);
}

void jaugeEssenceHenri::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

//début jauge à essence

    QRect carre(-280,-280,560,560);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(QPen(QBrush(QColor(250-valeur*2.5,valeur*2.5,0,80)) , 34, Qt::SolidLine,Qt::FlatCap));
    painter->drawArc(carre,231*16,80*16);//le fond de transparence 80

    painter->setPen(QPen(QBrush(QColor(250-valeur*2.5,valeur*2.5/2,0,255)) , 40, Qt::SolidLine,Qt::FlatCap));
    painter->drawArc(carre,231*16,valeur*16*0.8);//l'essence réel de transparence 255 (aucune transparence)

    QPixmap *test=new QPixmap(":/new/prefix1/iconeEssence.png");
    painter->drawPixmap(-15,265,30,30,*test);


//fin jauge essece

}
