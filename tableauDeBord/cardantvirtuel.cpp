#include "cadrantvirtuel.h"

cadrantVirtuel::cadrantVirtuel(QGraphicsItem *parent):QGraphicsItem(parent)
{

}

int cadrantVirtuel::getValeur() const
{
return valeur;
}

void cadrantVirtuel::setValeur(int value)
{
valeur = value;
}

int cadrantVirtuel::getValeurMax() const
{
return valeurMax;
}
