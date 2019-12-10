#include "maindisplay_youcef.h"
#include <QtMath>
#include <QGraphicsTextItem>
#include <QTime>



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


QRect rectDisplay(-95,-220,195,145);


QRadialGradient gradient(0, -140, 200);

       gradient.setColorAt(0.1, QColor("dark blue"));
       gradient.setColorAt(1, QColor("dark"));
       QBrush brush(gradient);
       painter->setBrush(brush);

painter->drawRect(rectDisplay);


painter->setPen(QPen(Qt::white, 15, Qt::SolidLine,Qt::FlatCap));


QTime time=QTime::currentTime();
time.currentTime();
QFont font("Seven Segment", 50,  QFont::Bold, true);
painter->setFont(font);
painter->drawText(-90,-130,time.toString("hh : mm"));




}
