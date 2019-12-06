#ifndef MAROUA_SCENE_H
#define MAROUA_SCENE_H

#include "maroua_scene.h"
#include "scene_globale.h"
#include "cadrantessence.h"
#include "cadranttour.h"
#include "cadrantvitesse.h"
#include "cadranttempmoteur.h"

#include "cadrantcontour.h"


class maroua_scene : public scene_globale
{

public:

    maroua_scene(scene_globale *parent = nullptr);


};

#endif // MAROUA_SCENE_H
