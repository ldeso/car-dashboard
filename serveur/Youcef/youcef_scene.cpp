#include "youcef_scene.h"
#include <QFontDatabase>

Youcef_Scene::Youcef_Scene(scene_globale* parent)
    : scene_globale(parent)
{
    CarDialerPrototype *MainDial = new CarDialerPrototype();
    MainDisplay_Youcef *Ecran = new MainDisplay_Youcef();
    Vitesse = new CarSpeedDial();
    CompteTours = new Tachometer();
    Essence= new FuelGauge();
    jaugeTemperature= new EngineHeatGauge();
    Clignotant = new FlashingLight_Youss();
    warning = new Warning_Youss();



    QFontDatabase::addApplicationFont(":/new/font/Seven_Segment.ttf");


    addItem(MainDial);
    addItem(Ecran);
    addItem(Vitesse);
    addItem(CompteTours);
    addItem(Essence);
    addItem(jaugeTemperature);
    addItem(Clignotant);
    addItem(warning);



}
