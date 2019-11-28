#include "jaugetoursminutehenri.h"

jaugeToursMinuteHenri::jaugeToursMinuteHenri(objet_virtuel *parent):objet_virtuel (parent)
{
    styleTexte="Uroob";
    value=0;
    valueMax=5400;
    tailleTextetoursMinute=20;

}

QRectF jaugeToursMinuteHenri::boundingRect() const
{
    return QRect(-800,-450,1600,900);
}

void jaugeToursMinuteHenri::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

//.....création des carrés de fond pour le disigne du cadrant........................

    QRect carre[10];
    for (int i=0;i<10;i++)
    {
        carre[i]=QRect(-300+i*5,-300+i*5,600-i*10,600-i*10);
    }

//.....fin création des carrés de fond pour le disigne du cadrant.....................








//.....Designe toursMinute....................................................
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(QPen(QBrush("gray") , 20, Qt::SolidLine,Qt::FlatCap));
    for (int i=225;i>-46;i-=1)
        {
        painter->drawArc(carre[9],i*16,10);
        }

    float green=qMax(qMin(255.0,-4.0*255/valueMax*value+4*255),0.0);//variation de la couleur verte
    float blue=qMin(250.0, qMax(0.0,-4.0*255/valueMax*value+3*255) );//variation de la couleur bleu
    painter->setPen(QPen(QBrush(QColor(250 , green , blue , 255 )) , 20, Qt::SolidLine,Qt::FlatCap));

    for (int i=225;i>224-qMin(270,(value/20*5400/valueMax));i-=1)
        {
        painter->drawArc(carre[9],i*16,10);
        }

//.....Fin Designe toursMinute....................................................







//.....Designe text pour tours min cadrant....................................................

    painter->setPen(QPen(QBrush(QColor(250 , green , blue , 255 )) , 20, Qt::SolidLine,Qt::FlatCap));
    painter->setFont(QFont(styleTexte, tailleTextetoursMinute , -1,false));
    float pi=3.14159265;
    int j=0;
    for (float i=71*pi/56;i>-14*pi/56;i-=12*pi/(27*8)*5400/valueMax)
    {
        painter->drawText(qCos(i)*220-16,-qSin(i)*220+5,QString("%1").arg(j));
        j+=2;
        if (j>value/100)
            painter->setPen(QPen(QBrush("gray") , 40, Qt::SolidLine,Qt::FlatCap));
    }

//.....fin Designe text pour tours min cadrant....................................................


}
