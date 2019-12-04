#ifndef JONAS_COMPTEURKM_H
#define JONAS_COMPTEURKM_H
#include "objet_virtuel.h"


class jonas_compteurKm : public objet_virtuel
{
public:
    jonas_compteurKm();
    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // JONAS_COMPTEURKM_H
