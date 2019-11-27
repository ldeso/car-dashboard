#include "cadrantvirtuel.h"

cadrantVirtuel::cadrantVirtuel(QGraphicsItem *parent):QGraphicsItem(parent)
{

}

int cadrantVirtuel::getValue() const
{
return valeur;
}

void cadrantVirtuel::setValue(int value)
{
valeur = value;
}

int cadrantVirtuel::getValueMax() const
{
return valeurMax;
}
