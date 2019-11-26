#ifndef AIGUILLE_H
#define AIGUILLE_H
#include <QGraphicsScene>
#include <QGraphicsItem>



class hugo_Aiguille : public QGraphicsItem
{
public:
   // hugo_Aiguille();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual void parametrage(int param_x,int param_y, int param_r,int,int,int);
    int x=0,y=0,r=100;
    int angle=0;
    int getValueMax();
    void setValue(int);

  int start;
   int end;
   int value;

};

#endif // AIGUILLE_H
