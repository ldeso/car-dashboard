#ifndef ICONE_H
#define ICONE_H
#include <QGraphicsItem>
#include <QPixmap>
class Voyant : public QGraphicsItem
{
public:
    Voyant(QPixmap map, QGraphicsItem * parent = nullptr);
    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setValeur(int valeur);
private:
    int valeur;
    QPixmap voyant;
};

#endif // ICONE_H
