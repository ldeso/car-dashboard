#ifndef VERRE_H
#define VERRE_H
#include <QGraphicsScene>
#include <QGraphicsItem>

class verre : public QGraphicsItem
{
public:
    verre();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual void parametrage(int x,int y, int r);
    int x=0,y=0,r=100;
};

#endif // VERRE_H
