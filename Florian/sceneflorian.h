#ifndef SCENEFLORIAN_H
#define SCENEFLORIAN_H
#include "sceneglobale.h"
#include "cadrantflorian.h"
#include "voyant.h"
class SceneFlorian : public sceneGlobale
{
public:

    SceneFlorian(QGraphicsScene *parent=nullptr);
    cadrantVirtuel * vitesse;
    cadrantVirtuel * essence;
    cadrantVirtuel * huile;
    cadrantVirtuel * toursMinute;
    Voyant * position;
    Voyant * croisement;
    Voyant * route;
    Voyant * brouillardAvant;
    Voyant * brouillardArriere;
    Voyant * noEssence;
    Voyant * noHuile;
    Voyant * clignotantGauche;
    Voyant * clignotantDroite;
    Voyant * refroidissement;
    Voyant * batterie;
    Voyant * warning;
    Voyant * ceinture;
    Voyant * noCeinture;
};

#endif // SCENEFLORIAN_H
