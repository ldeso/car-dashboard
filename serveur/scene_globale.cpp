///
///Classe dérivant de QGraphicsScene. Va servir de classe mère pour toutes les scènes, ce qui permettra de passer d'une scène à l'autre de façon dynamique.
/// Tous les objets utilisés dans le dashboard seront définis dans "scène_globale.h"
///

#include "scene_globale.h"

scene_globale::scene_globale(QGraphicsScene *parent):QGraphicsScene (parent)
{

}
