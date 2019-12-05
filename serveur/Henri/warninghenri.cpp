#include "warninghenri.h"

warninghenri::warninghenri()
{

}

QRectF warninghenri::boundingRect() const
{
    return QRect(-300,-300,600,600);
}

void warninghenri::paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*)
{
}
