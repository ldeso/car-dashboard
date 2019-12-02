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
    objet_virtuel *AdaptiveSuspensionDampers;
    objet_virtuel *AutomaticTransmissionMode;
    objet_virtuel *FrontAntifog;
    objet_virtuel *RearAntifog;
    objet_virtuel *SeatBelt;
    objet_virtuel *RearWindowHeating;
    objet_virtuel *CheckEngine;
    objet_virtuel *OpenDoorDriver;
    objet_virtuel *OpenDoorFrontPassenger;
    objet_virtuel *OpenDoorBackLeftPassenger;
    objet_virtuel *OpenDoorBackRightPassenger;
<<<<<<< HEAD

=======
>>>>>>> b8512f4f0bbc8994a52e09239ce5f98f33607cf6
};

#endif // SCENE_GLOBALE_H
