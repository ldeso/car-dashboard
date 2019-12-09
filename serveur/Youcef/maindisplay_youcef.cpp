#include "maindisplay_youcef.h"
#include <QtMath>
#include <QGraphicsTextItem>


MainDisplay_Youcef::MainDisplay_Youcef(QGraphicsItem *)
{

}

QRectF MainDisplay_Youcef::boundingRect() const
{
 return QRectF(-600, -400, 1200, 800);
}

void MainDisplay_Youcef::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
painter->setRenderHint(QPainter::Antialiasing);

/* creation ecran principale*/

//    QRect rectDisplay(-95,-220,195,145);
//    painter->setPen(QPen(QColor(0,0,0,0) , 1, Qt::SolidLine,Qt::FlatCap));
//    painter->setBrush(QColor(0,128,255,15));
//    painter->drawRect(rectDisplay);

// QRadialGradient radialGrad(QPointF(0, -150), 50);
// radialGrad.setColorAt(0, QColor(0,204,255));
// radialGrad.setColorAt(1, QColor(0, 128, 255));
// painter->setPen(QPen(QColor(0,204,255) , 1, Qt::SolidLine,Qt::FlatCap));

//    painter->drawRect(-90,133,245,5);

QRect rectDisplay(-95,-220,195,145);


QRadialGradient gradient(0, -140, 200);

       gradient.setColorAt(0.1, QColor("dark blue"));
       gradient.setColorAt(1, QColor("dark"));
       QBrush brush(gradient);
       painter->setBrush(brush);

painter->drawRect(rectDisplay);

}
