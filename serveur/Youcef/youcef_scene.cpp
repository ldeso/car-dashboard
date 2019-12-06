#include "youcef_scene.h"

Youcef_Scene::Youcef_Scene(scene_globale* parent)
    : scene_globale(parent)
{
    CarDialerPrototype *MainDial = new CarDialerPrototype();
    Vitesse = new CarSpeedDial();
    Tachometer *tacho = new Tachometer();
    FuelGauge *fuel = new FuelGauge();
    EngineHeatGauge *heat = new EngineHeatGauge();
    Clignotant = new voyantsYoucef();


    addItem(MainDial);
    addItem(Vitesse);
    addItem(tacho);
    addItem(fuel);
    addItem(heat);
    addItem(Clignotant);

}
