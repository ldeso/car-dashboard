#include "youcef_scene.h"

Youcef_Scene::Youcef_Scene(scene_globale* parent)
    : scene_globale(parent)
{
    addItem(MainDial);
    addItem(Speed);
    addItem(tacho);
    addItem(fuel);
    addItem(heat);
}
