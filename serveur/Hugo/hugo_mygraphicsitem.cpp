#include "hugo_mygraphicsitem.h"
#include <QtMath>
#include <QDebug>
#define pi 3.14159265

hugo_MyGraphicsitem::hugo_MyGraphicsitem()
{
}



QRectF hugo_MyGraphicsitem::boundingRect() const
{
    qreal penWidth = 5;
    return QRectF(-10 - penWidth / 2, -10 - penWidth / 2, 20 + penWidth, 20 + penWidth);
}

void hugo_MyGraphicsitem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHints(QPainter::Antialiasing);

    //Création du fond noir
    QBrush black_brush(QColor(Qt::black));
    painter->setBrush(black_brush);
    painter->drawRect(-450,-300,900,600);


    //Arc de cercle extérieur
    QRect carre(-100,-100,200,200);
    painter->setPen(QPen( QColor(51,102,153) ,2, Qt::SolidLine,Qt::FlatCap));
    painter->drawChord(carre,-60*16,300*16);

    //Affichage compteur vitesse
    painter->setPen(QPen(QColor(Qt::darkGray) , 1, Qt::SolidLine,Qt::FlatCap));
    painter->setFont(QFont("Arial", 9, -1,false));
    painter->drawText(-12,-30,"km/h");
    painter->drawText(-190,-10,"x1000rpm");

    //Compteur km
    painter->setPen(QPen(QColor(0,0,0,0) , 1, Qt::SolidLine,Qt::FlatCap));
    painter->setBrush(QColor(0,128,255,15));
    painter->drawRect(-45,25,90,40);
    QRadialGradient radialGrad(QPointF(0, 45), 50);
    radialGrad.setColorAt(0, QColor(0,204,255));
    radialGrad.setColorAt(1, QColor(0, 128, 255));
    painter->setPen(QPen(QColor(0,204,255) , 1, Qt::SolidLine,Qt::FlatCap));
    painter->setBrush(radialGrad);
    painter->drawRect(-40,30,80,30);

    painter->setPen(QPen(Qt::black, 1, Qt::SolidLine,Qt::FlatCap));
    painter->setFont(QFont("Arial", 5, -1,false));
    painter->drawText(-38,40,"SPEED");
    painter->drawText(-38,55,"TRIP");

    painter->setFont(QFont("Arial", 9, -1,false));
    painter->drawText(0,45,QString("%1").arg(current_speed));
    painter->drawText(0,60, QString::number(km, 'f', 1));


    painter->setPen(QPen(QColor( 26, 13, 0), 1, Qt::SolidLine,Qt::FlatCap));
    painter->setBrush(QColor( 26,13,0));
    painter->drawRect(-45,100,90,10);

    painter->setFont(QFont("Arial", 8, -1,false));
    painter->setPen(QPen(QColor(255, 153, 51), 1, Qt::SolidLine,Qt::FlatCap));
    painter->drawText(-38,110,station);
    QRect carre_rpm(115,-100,80,80);
     painter->setBrush(black_brush);
    painter->setPen(QPen(QColor(25,25,25) ,1, Qt::SolidLine,Qt::FlatCap));
    painter->drawEllipse(carre_rpm);
      QRect carre_rpm2(120,-10,80,80);
      painter->drawEllipse(carre_rpm2);

      //Affichage régime moteur
      painter->setFont(QFont("Arial", 8, -1,false));
      painter->setPen(QPen(QColor(Qt::darkGray), 1, Qt::SolidLine,Qt::FlatCap));
      QStringList Regimes;
      Regimes<<"P"<<"R"<<"N"<<"D"<<"3"<<"2"<<"L";
      float teta=-30*3.14159/180;
      int i=0;
      while (i<7){
          teta+=10*3.14159/180;
          if (i==3){
              QRadialGradient radialGrad(QPointF(110*(qCos(teta))+4,110*(qSin(teta))-3), 12);
              radialGrad.setColorAt(0, QColor(0,255,0,80));
              radialGrad.setColorAt(1, QColor(0,0,0,0));
              painter->setPen(QPen(QColor(0,0,0,0) , 1, Qt::SolidLine,Qt::FlatCap));
              painter->setBrush(radialGrad);
              painter->drawEllipse(QPointF(110*(qCos(teta))+4,110*(qSin(teta))-3),20,20);
              painter->setPen(QPen(QColor(Qt::green), 1, Qt::SolidLine,Qt::FlatCap));
          }
          else{
              painter->setPen(QPen(QColor(Qt::darkGray), 1, Qt::SolidLine,Qt::FlatCap));
          }
          painter->drawText(110*(qCos(teta)),110*(qSin(teta)),Regimes[i]);
      i++;
      }

//   QLinearGradient linearGrad(QPointF(80*qCos(225)-170, -80*qSin(225)+20), QPointF(-170, 20));
//    linearGrad.setColorAt(0, QColor(255,255,255,80));
//    linearGrad.setColorAt(1, QColor(0,0,0,80));
//    painter->setBrush(linearGrad);
//    painter->setPen(QPen( QColor(51,102,153) ,5, Qt::SolidLine,Qt::FlatCap));
//    painter->drawChord(-170,-20,160,160,80*16,210*16);

}
