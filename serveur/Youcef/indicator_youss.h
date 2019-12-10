#ifndef INDICATOR_YOUSS_H
#define INDICATOR_YOUSS_H

#include "objet_virtuel.h"


class Indicator_Youss : public objet_virtuel
{
public:
    Indicator_Youss(int,int, QString, int, int, QColor);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:

    QString path;
    int x,y;
    int width=30;
    int height=30;
    QColor color;
};

#endif // INDICATOR_YOUSS_H
