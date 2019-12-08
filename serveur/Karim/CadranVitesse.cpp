#include "Karim/CadranVitesse.h"
#include "qmath.h"
#include <QFont>
#include <QDateTime>
#include <QFontDatabase>
#include <qdebug.h>
#define pi 3.1415


CadranVitesse::CadranVitesse()
{
    valueMax=270; //Vitesse max
    value=0;
}

QRectF CadranVitesse::boundingRect() const
{
    qreal penWidth = 5;
    return QRectF(-10 - penWidth / 2, -10 - penWidth / 2, 20 + penWidth, 20 + penWidth);
}

void CadranVitesse::paint(QPainter *painter, const QStyleOptionGraphicsItem* ,QWidget* )
{
    /* static const QPointF points[6] = {
          QPointF(400, 170),
          QPointF(400, -120),
          QPointF(800, -360),
          QPointF(-200, -360),
          QPointF(200, -120),
          QPointF(200, 170)
      };

      painter->setPen(QPen(QBrush("white"),8,Qt::SolidLine,Qt::RoundCap));
      painter->setBrush(Qt::darkCyan);
      painter->setRenderHints(QPainter::Antialiasing);
      painter->drawPolygon(points, 6);*/

// Ajout des carree qui vont servir à dessiner nos objets
QRect carre[13];
   for (int i=0;i<13;i++)
    {
        carre[i]=QRect(-200+i*5,-200+i*5,400-i*10,400-i*10);
    }

    painter->setRenderHints(QPainter::Antialiasing);

  // Design du cercle aiguille
   painter->setBrush(Qt::darkRed);
   painter->setPen(QPen(QBrush("darkRed"),8,Qt::SolidLine));
   painter->drawEllipse(-20,-20,40,40);


   //Design du cadran vitesse
   painter->setPen(QPen(QBrush("gray") , 5, Qt::SolidLine,Qt::FlatCap));
   painter->drawArc(carre[4],300*16,300*16);
   painter->drawLine(92, 155, -92, 155);
   painter->setPen(QPen(QBrush("blue") , 5, Qt::SolidLine,Qt::FlatCap));
   painter->drawArc(carre[2],300*16,300*16);
   painter->drawLine(96, 165, -96, 165);

    //Ajout des traits
    painter->setPen(QPen(QBrush("white") , 10, Qt::SolidLine,Qt::FlatCap));

    int k=2;
     for (float i=225;i>-46;i-=10.0*270/270)
         {
         if(k%2==0)
            painter->drawArc(carre[6],i*16,8*4);
         else
             painter->drawArc(carre[6],i*16,8);
          k++;
         }

    //Ajout des graduations
    painter->setPen(QPen(QBrush("white") ,10, Qt::SolidLine,Qt::FlatCap));
    painter->drawText(QRectF(-200,-100,400,400),Qt::AlignCenter,"Km/h");
     int j=0;
     for (float i=35*pi/28;i>=-7*pi/28;i-=12*pi/(27*4)*270/(270+1))
     {
         painter->drawText(qCos(i)*145-6,-qSin(i)*145+6,QString("%1").arg(j*2));
         j+=10;
     }

    //Design et rotation de l'aiguille
     painter->rotate(getValue()+225);
     painter->setPen(QPen( Qt::darkRed , 8, Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin));
     painter->drawLine(0, -22, 0, -170);
     painter->rotate(-(getValue()+225));

    //Design du rectangle
     painter->setPen(QPen( Qt::black , 2, Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin));
     QRadialGradient radialGrad2(QPointF(-100, 0), 300);
           radialGrad2.setColorAt(0, QColor(0, 128, 255));
           radialGrad2.setColorAt(1, Qt::cyan);
     painter->setBrush(radialGrad2);

     painter->translate(405,45);
     painter->drawRect(-200,-70,190,190);
     painter->drawLine(-200,25,0,25);

     //Ajout d'une police LCD
     int id = QFontDatabase::addApplicationFont(":/LCDfont.ttf");
     QString family = QFontDatabase::applicationFontFamilies(id).at(0);
     QFont F(family);
     F.setPixelSize(32);
     painter->setFont(F);
     painter->setPen(QPen(Qt::darkBlue));

     //Ajout de l'heure
     painter->drawText(QRectF(-50,-30,-135,200),Qt::AlignCenter,QString::number(getValue(),'f',1)+" km/h");
     QString sDate = QDateTime::currentDateTime().toString("hh:mm");
     painter->drawText(QRectF(-50,-120,-100,200),Qt::AlignCenter,QString("%1").arg(sDate));

}

