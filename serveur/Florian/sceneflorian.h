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
    //cadrantVirtuel * vitesse;
    //cadrantVirtuel * essence;
    //cadrantVirtuel * huile;
    //cadrantVirtuel * toursMinute;
    /*Voyant * position;
    Voyant * croisement;
    Voyant * route;*/
    FlorianVoyant * tempHuile;
    FlorianVoyant * essenceIcon;
    FlorianVoyant * brouillardAvant;
    FlorianVoyant* brouillardArriere;
    FlorianVoyant* noEssence;
    FlorianVoyant* noHuile;
    /*Voyant * clignotantGauche;
    Voyant * clignotantDroite;*/
    FlorianVoyant* refroidissement;
    FlorianVoyant* batterie;
    //Voyant * warning;
    FlorianVoyant* ceinture;
    FlorianVoyant* noCeinture;
};

#endif // SCENEFLORIAN_H
