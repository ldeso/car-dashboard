#include "hugo_compteur.h"
#include <QPainter>
#include <QtMath>
#include <QDebug>
#define pi 3.14159265


hugo_Compteur::hugo_Compteur()
{

}


QRectF hugo_Compteur::boundingRect() const
{
    qreal penWidth = 5;
    return QRectF(-10 - penWidth / 2, -10 - penWidth / 2, 20 + penWidth, 20 + penWidth);
}

void hugo_Compteur::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHints(QPainter::Antialiasing);
    QRect carre_rpm(x-r,y-r,2*r,2*r);
    painter->setPen(QPen( couleur ,2, Qt::SolidLine,Qt::FlatCap));
    painter->drawArc(carre_rpm,start_angle*16,(end_angle-start_angle)*16);
    painter->setPen(QPen(couleurgrad ,5, Qt::SolidLine,Qt::FlatCap));
    for (int i=1;i<5;i++){
        QRect carre_grad(x-(r-i),y-(r-i),2*(r-i),2*(r-i));
        painter->drawArc(carre_grad,start_angle*16,(end_angle-start_angle)*16);
    }
    if (critique!=100){
        painter->setPen(QPen( QColor(0,0,0) ,5, Qt::SolidLine,Qt::FlatCap));
        for (int i=1;i<5;i++){
            QRect carre_grad(x-(r-i),y-(r-i),2*(r-i),2*(r-i));
            painter->drawArc(carre_grad,98*16,-39*16);
        }
        painter->setPen(QPen( couleur2 ,2, Qt::SolidLine,Qt::FlatCap));
        painter->drawArc(carre_rpm,98*16,-39*16);
        painter->setPen(QPen( couleurgrad2 ,5, Qt::SolidLine,Qt::FlatCap));
        for (int i=1;i<5;i++){
            QRect carre_grad(x-(r-i),y-(r-i),2*(r-i),2*(r-i));
            painter->drawArc(carre_grad,98*16,-39*16);
        }
    }
    painter->setPen(QPen( couleur ,1, Qt::SolidLine,Qt::FlatCap));
    int compteur=0;
    while (compteur<=nbre_graduations)
    {
        float i=start_angle*1.0+compteur*(end_angle*1.0-start_angle*1.0)/(nbre_graduations*1.0);
        if (compteur>critique){
            painter->setPen(QPen( couleur2 ,1, Qt::SolidLine,Qt::FlatCap));
        }
        painter->drawLine((r-10)*qCos(i*(pi/180))+x,-(r-10)*qSin(i*(pi/180))+y,(r)*qCos(i*(pi/180))+x,-(r)*qSin(i*(pi/180))+y);
        compteur++;
    }
    compteur=0;
    painter->setPen(QPen( couleur ,1, Qt::SolidLine,Qt::FlatCap));
    while (compteur<=nbre_graduations-1)
    {
        float i=start_angle*1.0+(end_angle*1.0-start_angle*1.0)/(nbre_graduations*2.0)+compteur*(end_angle*1.0-start_angle*1.0)/(nbre_graduations*1.0);
        if (compteur>critique){
            painter->setPen(QPen( couleur2 ,1, Qt::SolidLine,Qt::FlatCap));
        }
        painter->drawLine((r-5)*qCos(i*(pi/180))+x,-(r-5)*qSin(i*(pi/180))+y,(r)*qCos(i*(pi/180))+x,-(r)*qSin(i*(pi/180))+y);
        compteur++;
    }
    int j=0;
    painter->setPen(QPen(QColor(Qt::darkGray) , 1, Qt::SolidLine,Qt::FlatCap));
    painter->setFont(QFont("Arial", 9, -1,false));
    compteur=0;
    while (compteur<=nbre_graduations)
    {
        float i=start_angle*1.0+compteur*(end_angle*1.0-start_angle*1.0)/(nbre_graduations*1.0);
        painter->drawText(qCos(i*pi/180)*(r-20)+x-11,-qSin(i*pi/180)*(r-20)+y+3,graduations[j]);
        j++;
        compteur++;
    }
}

void hugo_Compteur::Parametrage(int param_x, int param_y, int param_r,int param_start_angle, int param_end_angle,QStringList param_graduations,int red,int green,int blue,int param_critique, int red2,int green2,int blue2)
{
    x=param_x;
    y=param_y;
    r=param_r;
    start_angle=param_start_angle;
    end_angle=param_end_angle;
    nbre_graduations=param_graduations.length()-1;
    graduations=param_graduations;
    couleur=QColor(red,green,blue);
    couleurgrad=QColor(red,green,blue,20),
    critique=param_critique;
    couleur2=QColor(red2,green2,blue2);
    couleurgrad2=QColor(255,green2,blue2,20);

}

