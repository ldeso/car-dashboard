#include "cadranttempmoteur.h"
#include <QGraphicsItem>
#include <QPainter>
cadranthuile::cadranthuile(QGraphicsItem *parent)
{

}
QRectF cadranthuile::boundingRect() const
{
    QRectF rectf(-800,-500,1600,1000);
    return rectf;
}

void cadranthuile::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    QPen pen;
    painter->setRenderHint(QPainter::Antialiasing);

    ///création des traits désignants la température du moteur
       for (int i=0;i<=20;i+=1)
       {
           if(i%5==0){
               painter->setPen(QPen(QBrush("red"), 25, Qt::SolidLine, Qt::FlatCap));
               QRect rectTrait(100,-330,400,400);
               painter->drawArc(rectTrait,(50+i*3)*16,13);
           }
           else{
               pen.setWidthF(50);
               painter->setPen(QPen(QBrush("white"), 10, Qt::SolidLine, Qt::FlatCap));
               QRect rectTrait(100,-330,400,400);
               painter->drawArc(rectTrait,(50+i*3)*16,13);
           }
       }


   /*//création de l'aiguille temp Moteur

   {QPen pen;
   pen.setWidth(1);
   pen.setColor("white");
   QBrush brushAig(Qt::SolidPattern);
   brushAig.setColor("red");
   painter->setPen(pen);
   painter->setBrush(brushAig);
   QPointF pts[3]= {

       QPointF(380,45),
        QPointF(380,35),
       QPointF(500,90),
      };

      painter->drawConvexPolygon(pts, 3);}*/



   {QPen pen;
   pen.setColor("white");
   QBrush brush(Qt::SolidPattern);
   brush.setColor("white");
   painter->setPen(pen);
   painter->setBrush(brush);
   QRect recticone (310, -230, 20, 20);
   painter->drawEllipse(recticone);


         }
   }
