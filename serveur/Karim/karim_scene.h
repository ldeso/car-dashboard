#ifndef KARIM_SCENE_H
#define KARIM_SCENE_H
#include <Karim/CadranVitesse.h>
#include <Karim/cadrantourparmin.h>
#include <Karim/cadranEss.h>
#include <Karim/voyants.h>
#include <Karim/clignot.h>
#include <Karim/Voyant_batterie.h>
#include "scene_globale.h"


class karim_scene : public scene_globale
{
public:
    karim_scene();

    CadranTourParMin *CompteTours;
    CadranEss *Essence;
    CadranEss *Temperature;

    clignot * Clignotant;
    Voyants *VoyantBatterie;
};

#endif // KARIM_SCENE_H
