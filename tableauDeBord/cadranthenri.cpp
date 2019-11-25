#include "cadranthenri.h"

cadrantHenri::cadrantHenri(cadrantVirtuel *parent):cadrantVirtuel (parent)
{
    vitesse=0;
    toursMinute=0;

    styleTexte="Uroob";

    vitesseMax=270;
    epesseurTraitVitesse=10;
    tailleTexteVitesse=27;

    tailleTextetoursMinute=20;
    toursMinute=0;
    toursMinuteMax=5400;
}
QRectF cadrantHenri::boundingRect() const
{
    return QRect(-800,-450,1600,900);
}

void cadrantHenri::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{




//.....création des carrés de fond pour le disigne du cadrant........................

    QRect carre[10];
    for (int i=0;i<10;i++)
    {
        carre[i]=QRect(-300+i*5,-300+i*5,600-i*10,600-i*10);
    }

//.....fin création des carrés de fond pour le disigne du cadrant.....................







//.....Designe fond degradé rond derrierre cadrant....................................

    for (int i=90;i>40;i--)
    {
        painter->setPen(QPen( QColor(0,0,0,15) , i, Qt::SolidLine,Qt::FlatCap));
        painter->drawArc(carre[4],0,360*16);
    }

//.....Fin Designe fond degradé rond derrierre cadrant...................................








//.....Designe vitesse cadrant....................................................

    painter->setPen(QPen(QBrush("darkCyan") , 40, Qt::SolidLine,Qt::FlatCap));
    for (float i=225;i>-46;i-=10.0*270/vitesseMax)
        {
        painter->drawArc(carre[2],i*16,epesseurTraitVitesse);
        }

    painter->setPen(QPen(QBrush("darkCyan") , 30, Qt::SolidLine,Qt::FlatCap));
    for (float i=225;i>-46;i-=1.0*270/vitesseMax)
        {
        painter->drawArc(carre[4],i*16,epesseurTraitVitesse);
        }

    painter->setPen(QPen(QBrush("cyan") , 40, Qt::SolidLine,Qt::FlatCap));
    for (float i=225;i>224-qMin(270,(vitesse*270/vitesseMax));i-=10.0*270/vitesseMax)
        {
        painter->drawArc(carre[2],i*16,epesseurTraitVitesse);
        }

    painter->setPen(QPen(QBrush("cyan") , 30, Qt::SolidLine,Qt::FlatCap));
    for (float i=225;i>224-qMin(270,(vitesse*270/vitesseMax));i-=1.0*270/vitesseMax)
        {
        painter->drawArc(carre[4],i*16,epesseurTraitVitesse);
        }


//.....Fin designe vitesse cadrant...........................................





//.....Designe text pour vitesse cadrant.............................................

    painter->setPen(QPen(QBrush("cyan") , 40 , Qt::SolidLine,Qt::FlatCap));
    painter->drawText(carre[1],Qt::AlignCenter,"Bienvenue dans le cadrant de Henri V1.1");
    painter->setFont(QFont(styleTexte, tailleTexteVitesse, -1,false));
    float pi=3.14159265;
    int j=0;
    for (float i=35*pi/28;i>=-7*pi/28;i-=6*pi/(27*4)*270/(vitesseMax+1))
    {


        painter->drawText(qCos(i)*345-18,-qSin(i)*345+13,QString("%1").arg(j));
        j+=10;
        if (j>vitesse)
            painter->setPen(QPen(QBrush("darkCyan") , 40, Qt::SolidLine,Qt::FlatCap));
    }

//.....fin Designe text pour vitsse cadrant...............................................................







//.....Designe toursMinute....................................................

    painter->setPen(QPen(QBrush("gray") , 20, Qt::SolidLine,Qt::FlatCap));
    for (int i=225;i>-46;i-=1)
        {
        painter->drawArc(carre[9],i*16,10);
        }

    float green=qMax(qMin(255.0,-4.0*255/toursMinuteMax*toursMinute+4*255),0.0);//variation de la couleur verte
    float blue=qMin(250.0, qMax(0.0,-4.0*255/toursMinuteMax*toursMinute+3*255) );//variation de la couleur bleu
    painter->setPen(QPen(QBrush(QColor(250 , green , blue , 255 )) , 20, Qt::SolidLine,Qt::FlatCap));

    for (int i=225;i>224-qMin(270,(toursMinute/20*5400/toursMinuteMax));i-=1)
        {
        painter->drawArc(carre[9],i*16,10);
        }

//.....Fin Designe toursMinute....................................................







//.....Designe text pour tours min cadrant....................................................

    painter->setPen(QPen(QBrush(QColor(250 , green , blue , 255 )) , 20, Qt::SolidLine,Qt::FlatCap));
    painter->setFont(QFont(styleTexte, tailleTextetoursMinute , -1,false));
    j=0;
    for (float i=35*pi/28;i>-7*pi/28;i-=6*pi/(27*4)*5400/toursMinuteMax)
    {
        painter->drawText(qCos(i)*220-16,-qSin(i)*220+5,QString("%1").arg(j));
        j+=2;
        if (j>toursMinute/100)
            painter->setPen(QPen(QBrush("gray") , 40, Qt::SolidLine,Qt::FlatCap));
    }

//.....fin Designe text pour tours min cadrant....................................................

}
