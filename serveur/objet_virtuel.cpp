#include "objet_virtuel.h"

objet_virtuel::objet_virtuel(QGraphicsItem *parent):QGraphicsItem(parent)
{

}

int objet_virtuel::getValue() const
{
return value;
}

void objet_virtuel::setValue(int value)
{
value = value;
}

int objet_virtuel::getValueMax() const
{
return valueMax;
}
