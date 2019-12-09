#include "youcef_scene.h"
#include <QFontDatabase>


Youcef_Scene::Youcef_Scene(scene_globale* parent)
    : scene_globale(parent)
{
    CarDialerPrototype *MainDial = new CarDialerPrototype();
    addItem(MainDial);

    MainDisplay_Youcef *Ecran = new MainDisplay_Youcef();
    addItem(Ecran);

    QFontDatabase::addApplicationFont(":/new/font/Seven_Segment.ttf");

    Vitesse = new CarSpeedDial();

    CompteTours = new Tachometer();
    addItem(CompteTours);

    Essence= new FuelGauge();
    addItem(Essence);

    jaugeTemperature= new EngineHeatGauge();
    addItem(jaugeTemperature);


    Clignotant = new FlashingLight_Youss();
    addItem(Clignotant);

    warning = new Warning_Youss();
    addItem(warning);

    position =new Indicator_Youss(340,-60,":/new/logos/Icones/dayLight.gif",80,80,Qt::green);
    position->setValue(1);
    addItem(position);

    route =new Indicator_Youss(340,-60,":/new/logos/Icones/dayLight.gif",80,80,Qt::green);
    addItem(route);

    addItem(Vitesse);






}
