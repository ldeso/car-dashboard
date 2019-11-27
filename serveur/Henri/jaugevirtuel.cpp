#include "jaugevirtuel.h"

jaugeVirtuel::jaugeVirtuel(QGraphicsItem *parent):QGraphicsItem(parent)
{

}

int jaugeVirtuel::getValue() const
{
    return valeur;
}

void jaugeVirtuel::setValue(int value)
{
    valeur = value;
}

int jaugeVirtuel::getValueMax() const
{
    return valeurMax;
}
