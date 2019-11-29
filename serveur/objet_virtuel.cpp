///
///Classe dérivée de QGraphicsItem. Va servir de classe mère pour tous les objets du dashboardE.lle contient un float Value, et un float valueMax, tous deux en variables
/// protégées
///
///
#include "objet_virtuel.h"

objet_virtuel::objet_virtuel(QGraphicsItem *parent):QGraphicsItem(parent)
{

}

///
/// \brief Fonction renvoyant la variable value
/// \return
///
float objet_virtuel::getValue() const
{
return value;
}

///
/// \brief objet_virtuel::setValue. Permet de modifier la valeur de la variable value
/// \param set_value valeur à attribuer à value
///
void objet_virtuel::setValue(float set_value)
{
value = set_value;
}

///
/// \brief objet_virtuel::getValueMax Fonction renvoyant la valeur de valueMax
/// \return
///
int objet_virtuel::getValueMax() const
{
return valueMax;
}
