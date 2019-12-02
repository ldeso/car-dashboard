#ifndef JONAS_VOYANT_SIMPLE_H
#define JONAS_VOYANT_SIMPLE_H
#include "objet_virtuel.h"


class jonas_voyant_simple : public objet_virtuel
{
public:
    jonas_voyant_simple(QString, int, int, int);
    QRectF boundingRect() const override;
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*) override;
    int getValue() {return value;}

private:
    QString path;
    int value = 0;
    int size = 30;
    int x = 30, y = 30;
};

#endif // JONAS_VOYANT_SIMPLE_H
