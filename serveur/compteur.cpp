#include "compteur.h"
#include <QPainter>
#include <QPen>
#include <QStyleOptionGraphicsItem>
#include <QtMath>
#include <QDebug>
Compteur::Compteur(int x, int y, int width, int height, int speedMax, QGraphicsItem * parent):QGraphicsItem(parent)
{
    this->width = width;
    this->height = height;
    this->speedMax = speedMax;
    this->speed = 0;
    this->x = x;
    this->y = y;
}

QRectF Compteur::boundingRect()const
{
    QRectF rect(x,y,width,height);
    return rect;
}

void Compteur::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen2(QColor(40,40,40));
    QPen pen1(QColor(Qt::red));
    pen1.setWidth(5);
    pen2.setWidth(10);
    painter->setPen(pen2);
    painter->drawArc(x, y, width, height, 16*220,-260*16);
    painter->setPen(pen1);
    float f = generateAngle();
    painter->drawLine(x+width/2, y+height/2, cos(qDegreesToRadians(-220.0f+f))*(width/2-10)+ width/2 +x, sin(qDegreesToRadians(-220.0f+f))*(height/2-10) + height/2 + y);

}

void Compteur::setSpeed(int speed)
{
    this->speed = speed;
}

float Compteur::generateAngle()
{
    float angle = 0.0f;
    angle = (float)speed/speedMax * 260;
    return angle;
}

int Compteur::getSpeedMax()
{
    return speedMax;
}
