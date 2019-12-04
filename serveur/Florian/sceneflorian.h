#ifndef SCENEFLORIAN_H
#define SCENEFLORIAN_H
#include "scene_globale.h"
#include "cadrantflorian.h"
#include "florianvoyant.h"
#include "florianclignotant.h"
#include "floriancompteurkm.h"

class SceneFlorian : public scene_globale
{
public:

    SceneFlorian(QGraphicsScene *parent=nullptr);
    FlorianVoyant * tempHuile;
    FlorianVoyant * essenceIcon;
    FlorianVoyant * brouillardAvant;
    FlorianVoyant* brouillardArriere;
    FlorianVoyant* noEssence;
    FlorianVoyant* noHuile;
    FlorianVoyant* refroidissement;
    FlorianVoyant* batterie;
    FlorianVoyant* ceinture;
    FlorianVoyant* noCeinture;
};

#endif // SCENEFLORIAN_H
