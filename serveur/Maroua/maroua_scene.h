#ifndef MAROUA_SCENE_H
#define MAROUA_SCENE_H

#include "cadrantessence.h"
#include "cadrantvitesse.h"
#include "cadranttempmoteur.h"
#include "cadranttour.h"
#include "cadrantcontour.h"
#include "voyantsmaroua.h"
#include "warningmaroua.h"
#include "autresvoyants.h"
#include "scene_globale.h"

class maroua_scene : public scene_globale
{

public:

    maroua_scene(scene_globale *parent = nullptr);


};

#endif // MAROUA_SCENE_H
