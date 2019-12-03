#include "Karim/cadrantourparmin.h"
#include "qmath.h"
#include <QFont>
#define pi 3.1415


CadranTourParMin::CadranTourParMin(QGraphicsItem*)
{
    value=0;
    valueMax=8000; //Nombre de tours max
}

QRectF CadranTourParMin::boundingRect() const
{
    qreal penWidth = 5;
    return QRectF(-10 - penWidth / 2, -10 - penWidth / 2, 20 + penWidth, 20 + penWidth);
}

void CadranTourParMin::paint(QPainter *painter, const QStyleOptionGraphicsItem* ,QWidget* )
{

// Ajout des carree qui vont servir à dessiner nos objets
QRect carre[13];
   for (int i=0;i<13;i++)
    {
        carre[i]=QRect(-200+i*5,-200+i*5,400-i*10,400-i*10);
    }

   //Design du cercle de l'aiguille
    painter->setBrush(Qt::darkRed);
    painter->setPen(QPen(QBrush("darkRed"),7,Qt::SolidLine));
    painter->setRenderHints(QPainter::Antialiasing);
    painter->drawEllipse(-20,-20,40,40);

   //Design du cadran tours par minutes
   for (int i=5;i>0;i--)
    {
        painter->setPen(QPen( Qt::gray, i, Qt::SolidLine,Qt::FlatCap));
        painter->setRenderHints(QPainter::Antialiasing);
        painter->drawArc(carre[4],300*16,300*16);
        painter->drawLine(92, 155, -92, 155);
        painter->setPen(QPen(QBrush("blue") , i, Qt::SolidLine,Qt::FlatCap));
        painter->drawArc(carre[2],300*16,300*16);
        painter->drawLine(96, 165, -96, 165);
    }

   //Ajout des traits
    painter->setPen(QPen(QBrush("white") , 10, Qt::SolidLine,Qt::FlatCap));
    int k=0;
 for(float i=225;i>-46;i-=10.0*270/80)
  {
     if(k==6 || k==7  ||k==8)
     {
         painter->setPen(QPen(Qt::red ,8, Qt::SolidLine));
         if(k==6 || k==8)
            painter->drawArc(carre[6],i*16,8*4);
         if(k==7)
             painter->drawArc(carre[6],i*16,8);
     }
   if(k%2==0)
        painter->drawArc(carre[6],i*16,8*4);
   else
         painter->drawArc(carre[6],i*16,8);
      k++;
 }

   painter->setPen(QPen(QBrush("white") ,10, Qt::SolidLine,Qt::FlatCap));
   painter->drawText(QRectF(-70,50,150,80),Qt::AlignCenter,"*1000r/min");

   //Ajout des graduations
   int j=0;
   for(float i=35*pi/28;i>=-7*pi/28;i-=6*pi/(27*4)*270/(80+1))
     {
       painter->drawText(qCos(i)*150-6,-qSin(i)*150+6,QString("%1").arg(j/10));
       j+=10;
       if (j/10 == 6 || j/10 == 7 || j/10 == 8)
          painter->setPen(QPen(QBrush("red") , 40, Qt::SolidLine,Qt::FlatCap));
     }

   //Design de l'aiguille
   painter->rotate((getValue()-4000)*180./5300.);
   painter->setPen(QPen( Qt::darkRed , 8, Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin));
   painter->drawLine(0, 0, 0, -170);
   painter->setRenderHints(QPainter::Antialiasing);
   painter->rotate(-((getValue()-4000)*180./5300.));
}

