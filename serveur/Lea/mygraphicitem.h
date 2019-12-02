#ifndef MYGRAPHICITEM_H
#define MYGRAPHICITEM_H
#include <QGraphicsItem>
#include <QRectF>

class mygraphicItem: public QGraphicsItem
{
public:
    mygraphicItem(QGraphicsItem *parent = nullptr);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
   double xpos;
   double ypos;
   double xpos2;
   double ypos2;
   double xc;
   double yc;
   double xc2;
   double yc2;
   int v1; //vitesse
   const double pi=3.14159265359;




};

#endif // MYGRAPHICITEM_H
