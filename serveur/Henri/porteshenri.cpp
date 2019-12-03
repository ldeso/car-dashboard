#include "porteshenri.h"

portesHenri::portesHenri(objet_virtuel *parent):objet_virtuel (parent)
{
    value=0;
    DD->setValue(0);
    DG->setValue(0);
    PG->setValue(0);
    PD->setValue(0);
    C->setValue(0);
}

QRectF portesHenri::boundingRect() const
{
    return QRect(-500,-300,1000,600);
}

void portesHenri::paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*)
{

}
