#ifndef COMPTEUR_H
#define COMPTEUR_H

#include <QGraphicsItem>

class Compteur : public QGraphicsItem
{
public:
    Compteur(int x = 0, int y = 0, int width = 5, int height = 5, int speedMax=200, QGraphicsItem * parent = NULL);
    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setSpeed(int speed);
    float generateAngle();
    int getSpeedMax();
private:
    int x;
    int y;
    int width;
    int height;
    int speedMax;
    int speed;
};

#endif // COMPTEUR_H
