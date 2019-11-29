#ifndef SCENE_GLOBALE_H
#define SCENE_GLOBALE_H
#include "objet_virtuel.h"


class scene_globale : public QGraphicsScene
{
public:
    scene_globale(QGraphicsScene *parent=nullptr);

    objet_virtuel *Vitesse;
    objet_virtuel *Essence;
    objet_virtuel *CompteTours;
    objet_virtuel *jaugeTemperature;
    objet_virtuel *Clignotant;
    objet_virtuel *VoyantBatterie;
    objet_virtuel *position;
    objet_virtuel *croisement;
    objet_virtuel *route;
    objet_virtuel * warning;
    objet_virtuel *CompteurKm;
};

#endif // SCENE_GLOBALE_H
