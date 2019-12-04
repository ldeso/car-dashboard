#include "speedometer_lea.h"
#include <QGraphicsItem>
#include <QObject>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QRectF>
#include <QtMath>
#include <QtDebug>
#include <QPointF>


speedometer_Lea::speedometer_Lea(double param_x, double param_y, double param_r, int param_start, int param_end, int param_spanAngle, int param_vitMax)

{
    x= param_x;
    y=param_y;
    r=param_r;
    angle_debut=param_start;
    angle_fin = param_end;

    span_angle=param_spanAngle;
    valueMax=param_vitMax;
}

QRectF speedometer_Lea::boundingRect() const
{
    QRectF rectf(0,0,1000,500);
    return rectf;
}

void speedometer_Lea::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*)
{
//    int v;
    if (value>=0 && value <=valueMax) {v=qRound(value);}
    else if (value<0) {v=0;}
    else {v=valueMax;}
    QPen pen;
    QBrush brush(Qt::SolidPattern);
//    brush.setColor("#733701");
//    painter->fillRect(this->boundingRect(),brush);


    // ******************** Dessine l'arc au dessus du compteur

    painter->setRenderHint(QPainter::Antialiasing);

            QRadialGradient radial(QPointF(x,y),180);
            radial.setColorAt(0,Qt::transparent);
            radial.setColorAt(0.95,Qt::blue);
            radial.setColorAt(1,Qt::transparent);
            painter->setPen(QPen(QBrush(radial),20,Qt::SolidLine,Qt::FlatCap));
            painter->drawArc((x-r-20),(y-r-20),(r*2)+40,(r*2)+40,(angle_debut+85)*16,(span_angle+10)*16);
            pen.setColor(Qt::transparent);
            pen.setCapStyle(Qt::RoundCap);
            painter->setPen(pen);


// ******************** Dessine les traits du compteur vitesse
    {   pen.setColor(Qt::white);
        for (int i=0;i<=valueMax;i+=10)
        {
        i%20==0 ? pen.setWidth(5) : pen.setWidth(2) ;
        pen.setColor(Qt::white);
            if (i==50 || i==90 || i==130)
            {
                pen.setColor(Qt::red);
            }
            pen.setCapStyle(Qt::FlatCap);
            pen.setStyle(Qt::SolidLine);
            painter->setPen(pen);

            painter->drawLine((x+r*(cos((angle_debut-(i*span_angle/valueMax))*pi/180))),(y-r*(sin((angle_debut-(i*span_angle/valueMax))*pi/180))),(x+(r-20)*(cos((angle_debut-(i*span_angle/valueMax))*pi/180))),(y-(r-20)*(sin((angle_debut-(i*span_angle/valueMax))*pi/180))));

            pen.setColor(Qt::white);
            painter->setPen(pen);
            painter->setRenderHint(QPainter::Antialiasing);
            QFont font("Bell",12, QFont::Bold);
            painter->setFont(font);
        if (i%20==0)
            painter->drawText((x-15+(r-40)*(cos((angle_debut-(i*span_angle/valueMax))*pi/180))),(y+8-(r-40)*(sin((angle_debut-(i*span_angle/valueMax))*pi/180))),QString("%1").arg(i));

        }
    }






// ******************** Dessine l'aiguille


    painter->setRenderHints(QPainter::Antialiasing);
    brush.setStyle(Qt::SolidPattern);
    pen.setWidth(1);
    pen.setColor(Qt::red);
    brush.setColor(Qt::red);
    pen.setJoinStyle(Qt::RoundJoin);
    painter->setPen(pen);
    painter->setBrush(brush);
    QPointF points[3] =
    {
          QPointF(x-9*cos((angle_debut-(span_angle*1.0f/valueMax)*value-90)*pi/180),y+9*sin((angle_debut-(span_angle*1.0f/valueMax)*value-90)*pi/180)),     //xc -9(taille rayon base aiguille)*cos (angle -90(angle droit aiguille))
          QPointF(x+r*(cos((angle_debut-(span_angle*1.0f/valueMax)*value)*pi/180)), y-r*(sin((angle_debut-(span_angle*1.0f/valueMax)*value)*pi/180))),
          QPointF(x+9*cos((angle_debut-(span_angle*1.0f/valueMax)*value-90)*pi/180),y-9*sin((angle_debut-(span_angle*1.0f/valueMax)*value-90)*pi/180))
     };

    painter->drawConvexPolygon(points, 3);


// ******************** Dessine le cercle au centre du cadran par dessus la fin de l'aiguille
    pen.setColor(Qt::transparent);
    QLinearGradient linearGradie(QPointF(385, 185), QPointF(415, 215));
       linearGradie.setColorAt(0,"#9d0409" );
       linearGradie.setColorAt(1,Qt::red);
    QBrush brush9(linearGradie)  ;
    painter->setPen(pen);
    painter->setBrush(brush9);
    painter->drawEllipse(x-20,y-20,40,40);

brush.setColor(Qt::black);
QLinearGradient linearGradi(QPointF(415, 215), QPointF(385, 185));
   linearGradi.setColorAt(0, "#9d0409");
   linearGradi.setColorAt(1,"#5e0407");
QBrush brush8(linearGradi)  ;
painter->setPen(pen);
painter->setBrush(brush8);
painter->drawEllipse(x-15,y-15,30,30);


// ******************** Dessine l'affichage de la vitesse

pen.setColor(Qt::white);

QFont font("Seven Segment",30);
painter->setFont(font);
QRectF affiche_km (x-90,y+80,80,70);
pen.setCapStyle(Qt::SquareCap);
painter->setPen(pen);
painter->drawText(affiche_km, Qt::AlignRight ,QString("%1").arg(value));
QFont font2("Times",20);
painter->setFont(font2);
painter->drawText(x+10,y+115,"km/h");

}



void speedometer_Lea::parametrage(double param_x, double param_y, double param_r, int param_start, int param_end, int param_spanAngle, int param_vitMax)
{

    x= param_x;
    y=param_y;
    r=param_r;
    angle_debut=param_start;
    angle_fin = param_end;

    span_angle=param_spanAngle;
    valueMax=param_vitMax;

}



void speedometer_Lea::setValue(int v)
{
    value=v;
}
