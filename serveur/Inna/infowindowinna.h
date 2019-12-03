#ifndef INFOWINDOWINNA_H
#define INFOWINDOWINNA_H
#include <QGraphicsItem>
#include <QRectF>
#include <QFont>

class InfoWindowInna : public QGraphicsItem
{
public:
    InfoWindowInna(QGraphicsItem *parent = nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int r;
private:
    double xc = 0.7*this->boundingRect().width(); //center of the rectangle
    double yc = 0.55*this->boundingRect().height(); //center of the rectangle
};

#endif // INFOWINDOWINNA_H

