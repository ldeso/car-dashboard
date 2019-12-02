#include "leo_scene.h"
#include "objet_virtuel.h"
#include "leo_indicator.h"

Leo_scene::Leo_scene(scene_globale *parent) :
    scene_globale(parent)
{
    VoyantBatterie = new Leo_indicator;
    addItem(VoyantBatterie);
}
