#ifndef VOYANT_H
#define VOYANT_H
#include <QGraphicsItem>


class hugo_voyant : public QGraphicsItem
{
public:
    hugo_voyant();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int on=0;
    virtual void parametrage(int param_x,int param_y, QString param_chemin,QString param_chemin2="vide",int red=255,int green=0,int blue=0);
    int x,y;
    QString chemin,chemin2;
    QColor couleur;
    void setValue(int);
    int getValue();
};


#endif // VOYANT_H
