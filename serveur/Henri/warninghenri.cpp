#include "warninghenri.h"

warninghenri::warninghenri()
{

}

QRectF warninghenri::boundingRect() const
{
    return QRect(-500,-300,1000,600);
}

void warninghenri::paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*)
{
}
