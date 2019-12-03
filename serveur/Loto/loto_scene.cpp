#include "loto_scene.h"
#include <QGraphicsScene>
#include "scene_globale.h"
#include "QGraphicsItem"
#include "loto_dashboard.h"
#include "fuel_guage.h"
#include "tachometre.h"
#include "tempgauge.h"
#include "leds.h"
#include "objet_virtuel.h"

loto_scene::loto_scene(scene_globale *parent):scene_globale(parent)
{
    loto_dashboard *dashboard = new loto_dashboard();
    this->addItem(dashboard);

    fuel_guage * fuelGauge = new fuel_guage();
    this->addItem(fuelGauge);

    tachometre * tachometer = new tachometre();
    this->addItem(tachometer);

    tempGauge * EngineTemp = new tempGauge();
    this->addItem(EngineTemp);

    LEDS * mySeatBelt= new LEDS(-130,0,":/bootOpen_red.gif",235,0,0,60);
    this->addItem(dashboard);


}
