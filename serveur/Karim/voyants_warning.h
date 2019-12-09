#ifndef VOYANTS_WARNING_H
#define VOYANTS_WARNING_H
#include "objet_virtuel.h"

class voyants_warning : public objet_virtuel
{
public:
    voyants_warning();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

private:
    int enabled;
    void updateWarning();
};

#endif // VOYANTS_WARNING_H
