#ifndef VERRE_H
#define VERRE_H
#include <QGraphicsScene>
#include <QGraphicsItem>

class hugo_verre : public QGraphicsItem
{
public:
    hugo_verre();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual void parametrage(int x,int y, int r,int a);
    int x=0,y=0,r=100,a=1;
};

#endif // VERRE_H
