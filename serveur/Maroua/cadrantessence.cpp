#include "cadrantessence.h"
#include <QGraphicsItem>
#include <QObject>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QRectF>
#include <QtMath>
#include <QtDebug>
#include <QPointF>
#include <QDateTime>

cadrantessence::cadrantessence(QGraphicsItem *parent)
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
       {
           if(i%5==0){
               painter->setPen(QPen(QBrush("red"), 25, Qt::SolidLine, Qt::FlatCap));
               QRect rectTrait(100,-330,400,400);
               painter->drawArc(rectTrait,(-70+i*3)*16,-13);
           }
           else{
               pen.setWidthF(50);
               painter->setPen(QPen(QBrush("white"), 10, Qt::SolidLine, Qt::FlatCap));
               QRect rectTrait(100,-330,400,400);
               painter->drawArc(rectTrait,(-70+i*3)*16,-13);
           }
       }



//création de l'aiguille essence

/*{QPen pen;
pen.setWidth(1);
pen.setColor("white");
QBrush brushAig(Qt::SolidPattern);
brushAig.setColor("red");
painter->setPen(pen);
painter->setBrush(brushAig);
QPointF pts[3]= {

QPointF(380,-30),
 QPointF(380,-20),
QPointF(500,-80),
};

painter->drawConvexPolygon(pts, 3);}*/



{QPen pen;
pen.setColor("white");
QBrush brush(Qt::SolidPattern);
brush.setColor("white");
painter->setPen(pen);
painter->setBrush(brush);
QRect recticone (370, -80, 20, 20);
painter->drawEllipse(recticone);


  }

}
