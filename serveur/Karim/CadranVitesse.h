#ifndef CadranVitesse_H
#define CadranVitesse_H
#include <objet_virtuel.h>


class CadranVitesse : public objet_virtuel
{

public:
    CadranVitesse();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

 };


#endif // CadranVitesse_H
