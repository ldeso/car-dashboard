#include "leo_gauge.h"
#include "leo_indicator.h"
#include "leo_scene.h"

Leo_scene::Leo_scene(scene_globale *parent) :
    scene_globale(parent)
{
    VoyantBatterie = new Leo_indicator;
    addItem(VoyantBatterie);
    Vitesse = new Leo_gauge;
    addItem(Vitesse);
}
