#include "youcef_scene.h"

Youcef_Scene::Youcef_Scene(scene_globale* parent)
    : scene_globale(parent)
{
    CarDialerPrototype *MainDial = new CarDialerPrototype();
    Vitesse = new CarSpeedDial();
    CompteTours = new Tachometer();
    Essence= new FuelGauge();
    jaugeTemperature= new EngineHeatGauge();
    Clignotant = new FlashingLight_Youss();
    warning = new Warning_Youss();


    addItem(MainDial);
    addItem(Vitesse);
    addItem(CompteTours);
    addItem(Essence);
    addItem(jaugeTemperature);
    addItem(Clignotant);
    addItem(warning);

}
