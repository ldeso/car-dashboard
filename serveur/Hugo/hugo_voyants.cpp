#include "hugo_voyants.h"

hugo_voyants::hugo_voyants(QGraphicsItem *parent):QGraphicsItem(parent)
{

}


int hugo_voyants::getValue() const
{
    return valeur;
}

void hugo_voyants::setValue(int value)
{
    valeur = value;
}

int hugo_voyants::getValueMax() const
{
    return valeurMax;
}
