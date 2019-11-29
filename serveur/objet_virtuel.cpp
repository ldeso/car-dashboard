#include "objet_virtuel.h"

objet_virtuel::objet_virtuel(QGraphicsItem *parent):QGraphicsItem(parent)
{

}

float objet_virtuel::getValue() const
{
return value;
}

void objet_virtuel::setValue(float set_value)
{
value = set_value;
}

int objet_virtuel::getValueMax() const
{
return valueMax;
}
