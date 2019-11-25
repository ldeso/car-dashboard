#include "jaugevirtuel.h"

jaugeVirtuel::jaugeVirtuel(QGraphicsItem *parent):QGraphicsItem(parent)
{

}

int jaugeVirtuel::getValeur() const
{
    return valeur;
}

void jaugeVirtuel::setValeur(int value)
{
    valeur = value;
}

int jaugeVirtuel::getValeurMax() const
{
    return valeurMax;
}
