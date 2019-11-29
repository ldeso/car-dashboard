#ifndef JONAS_SCENE_H
#define JONAS_SCENE_H
#include <QGraphicsScene>
#include "scene_globale.h"
#include "jonas_compteur.h"


class Jonas_scene : public scene_globale
{
public:
    Jonas_scene(scene_globale *parent = nullptr);
    Jonas_compteur *Vitesse;
    Jonas_compteur *CompteTours;
    Jonas_compteur *Essence;

};

#endif // JONAS_SCENE_H
