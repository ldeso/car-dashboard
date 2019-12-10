#include "cadranttour.h"
#include "objet_virtuel.h"
#include <QPainter>



cadranttour::cadranttour(objet_virtuel *parent)
{
  value=0;
  valueMax=8000;
}
QRectF cadranttour::boundingRect() const
{
    QRectF rectf(-800,-500,1600,1000);
    return rectf;
}

void cadranttour::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    float pi = 3.14159265359;
    painter->setRenderHint(QPainter::Antialiasing);
    QPen pen;

    ///création des traits désignants le tour minute

        for (int i=0;i<=40;i+=1)
        {
         if (i%5==0){
            pen.setWidthF(50);
            painter->setPen(QPen(QBrush("white"), 25, Qt::SolidLine, Qt::FlatCap));
            QRect rectTrait(-520,-330,400,400);
            painter->drawArc(rectTrait,(200-i*3)*16,3*3);
            }
         else{
             painter->setPen(QPen(QBrush("white"), 5, Qt::SolidLine, Qt::FlatCap));
             QRect rectTrait(-520,-330,400,400);
             painter->drawArc(rectTrait,(200-i*3)*16,5*3);}
    }
    {painter->setPen(QPen(QBrush("red") , 15, Qt::SolidLine));
    QRect rectt1 (-520, -330, 400,400);
    painter->drawArc(rectt1, 85*16, 6*16);
    painter->setPen(QPen(QBrush("red") , 15, Qt::SolidLine));
    QRect rectt2 (-520, -330, 400,400);
    painter->drawArc(rectt2, 100*16, 6*16);
    }

   ///création des nombres désignants les tours minute
    { int j=0;
        for (float i=200*pi/180; i>=77*pi/180; i-=14.25*pi/180)
        {
            if(j<6){
            painter->setFont(QFont("arial", 15, -1,false));
            painter->setPen(QPen(QBrush("white") , 40, Qt::SolidLine));
            painter->drawText(qCos(i)*175-320,-qSin(i)*175-130,QString("%1").arg(j));
            j+=1;
            }
            else{

                painter->setFont(QFont("arial", 15, -1,false));
                painter->setPen(QPen(QBrush("red") , 40, Qt::SolidLine));
                painter->drawText(qCos(i)*175-320,-qSin(i)*175-130,QString("%1").arg(j));
                j+=1;
                }
         }
     }

  ///création de l'aiguille tour minute

  {QPen pen;
  pen.setColor("white");
  QBrush brush(Qt::SolidPattern);
  brush.setColor("white");
  painter->setPen(pen);
  painter->setBrush(brush);
  QRect recticone (-370, -180, 30, 30);
  painter->drawEllipse(recticone);}

  {
  painter->setPen(QPen( Qt::white , 6, Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin));
  painter->drawLine(-360, -160, -460, -80);
  painter->rotate(200-(getValue()*14.25));


  }



}







