#ifndef HUGO_CLIGNOTANTS_H
#define HUGO_CLIGNOTANTS_H
#include <QGraphicsScene>
#include <QGraphicsItem>


class hugo_clignotants : public QGraphicsItem
{
public:
    hugo_clignotants();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int on=0;
    void setValue(int);
    void MAJ();
    int affiche=1;
};

#endif // HUGO_CLIGNOTANTS_H
