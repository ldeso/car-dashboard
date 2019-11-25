#ifndef AIGUILLE_H
#define AIGUILLE_H
#include <QGraphicsScene>
#include <QGraphicsItem>



class Aiguille : public QGraphicsItem
{
public:
    Aiguille();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual void parametrage(int param_x,int param_y, int param_r);
    int x=0,y=0,r=100;
    int angle=0;

};

#endif // AIGUILLE_H
