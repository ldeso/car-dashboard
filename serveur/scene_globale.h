#ifndef SCENE_GLOBALE_H
#define SCENE_GLOBALE_H
<<<<<<< HEAD
#include <QGraphicsItem>
=======
#include "objet_virtuel.h"
>>>>>>> 8a19226711a8db73f27b945a73ec4d350fc743b2


class scene_globale : public QGraphicsScene
{
public:
    scene_globale(QGraphicsScene *parent=nullptr);

    objet_virtuel *vitesse;
    objet_virtuel *Essence;
    objet_virtuel *CompteTours;
    objet_virtuel *jaugeTemperature;
    objet_virtuel *Clignotant;
    objet_virtuel *VoyantBatterie;
};

#endif // SCENE_GLOBALE_H
