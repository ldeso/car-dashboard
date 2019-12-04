#include "lea_scenedefond.h"
#include <QPainter>

lea_SceneDeFond::lea_SceneDeFond(QGraphicsItem *parent):QGraphicsItem (parent)
{

}

QRectF lea_SceneDeFond::boundingRect() const
{
    QRectF rectf(0,0,800,500);

    return rectf;
}

void lea_SceneDeFond::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
//    QRadialGradient gradient(0, 0, 1000);
//    gradient.setColorAt(0, QColor("darkCyan"));
//    gradient.setColorAt(1, QColor("dark"));
//    QBrush brush(gradient);
    QBrush brush;
    QPen pen;
    painter->setRenderHint(QPainter::Antialiasing);
    pen.setColor(Qt::blue);
    pen.setCapStyle(Qt::RoundCap);
    painter->setBrush(QBrush(Qt::black));
    painter->drawChord(100,10,900,450,310*16,280*16);
   // painter->drawChord((x-r-20),(y-r-20),(r*2)+40,(r*2)+40,(angle_debut+85)*16,(span_angle+10)*16);
    QPixmap texture_fond (":/Effets/effet_verre5.png");
    QPixmap voyant2= texture_fond.scaled(1000,600);
    brush.setTexture(voyant2);
   // painter->drawChord((x-r-15),(y-r-15),(r*2)+30,(r*2)+30,(angle_debut+85)*16,(span_angle+10)*16);

    painter->setBrush(brush);
    painter->setPen(pen);

   // painter->drawEllipse(-100,0,900,600);
    painter->drawChord(100,10,900,450,310*16,280*16);


    pen.setColor(Qt::blue);

    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawRoundedRect(100,400,900,80,20,20);

}


