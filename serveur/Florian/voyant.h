#ifndef ICONE_H
#define ICONE_H
#include <QGraphicsItem>
#include <QPixmap>
#include "../objet_virtuel.h"

class Voyant : public objet_virtuel
{
public:
    Voyant(QPixmap map, QGraphicsItem * parent = nullptr);
    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    QPixmap voyant;
};

#endif // ICONE_H
