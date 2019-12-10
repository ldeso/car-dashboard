#include "cadrantessence.h"
#include "objet_virtuel.h"
#include <QObject>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QRectF>
#include <QtMath>
#include <QtDebug>
#include <QPointF>
#include <QDateTime>

cadrantessence::cadrantessence(objet_virtuel *parent)
{

}
QRectF cadrantessence::boundingRect() const
{
    QRectF rectf(-800,-500,1600,1000);
    return rectf;
}

void cadrantessence::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    QPen pen;
    painter->setRenderHint(QPainter::Antialiasing);

    ///création des traits de gauge essence
       for (int i=0;i<=20;i+=1)
           for (int i=0;i<=20;i+=1)
           {
               if(i%5==0){
                   painter->setPen(QPen(QBrush("white"), 20, Qt::SolidLine, Qt::FlatCap));
                   QRect rectTrait(100,-330,400,400);
                   painter->drawArc(rectTrait,(-30+i*2)*16,-10);
               }
               else{
                   pen.setWidthF(50);
                   painter->setPen(QPen(QBrush("white"), 05, Qt::SolidLine, Qt::FlatCap));
                   QRect rectTrait(100,-330,400,400);
                   painter->drawArc(rectTrait,(-30+i*2)*16,-10);
               }
           }
       painter->setPen(QPen(QBrush("red") , 10, Qt::SolidLine));
       QRect rectt2 (100, -330, 400,400);
       painter->drawArc(rectt2, -27*16, 3.5*16);

  ///création de lettres désignants le niveau de carburant
 { painter->setFont(QFont("georgia", 12, -1,false));
 painter->setPen(QPen(QBrush("white"), 20, Qt::SolidLine, Qt::FlatCap));
 painter->drawText(QRectF(450,-190,50,50),Qt::AlignCenter,"F");
 painter->setPen(QPen(QBrush("RED"), 20, Qt::SolidLine, Qt::FlatCap));
 painter->drawText(QRectF(430,-60,50,50),Qt::AlignCenter,"E");
 QPixmap essence("/home/sahli/Bureau/Icones/voyant_carburant.jpg");
 painter->drawPixmap(370,-120,20,20,essence);}


   ///création de l'aiguille carburant et le cercle de son centre

  painter->setPen(QPen( Qt::white , 4, Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin));
  painter->drawLine(410, -110, 460, -155);

  {QPen pen;
  pen.setColor("white");
  QBrush brush(Qt::SolidPattern);
  brush.setColor("white");
  painter->setPen(pen);
  painter->setBrush(brush);
  QRect recticone (400, -115, 15, 15);
  painter->drawEllipse(recticone);
  }

}
