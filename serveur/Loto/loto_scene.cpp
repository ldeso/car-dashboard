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
#include "blinkingleds.h"
#include "kmcalculator.h"

///
///\file loto_scene.cpp
/// \brief Cet classe est derivé de scene globale et il est utilisé pour afficher toute les objet graphic item.
///

loto_scene::loto_scene(scene_globale *parent):scene_globale(parent)
{
    this->setBackgroundBrush(QBrush(Qt::black));

    Vitesse = new loto_dashboard();
    Essence = new fuel_guage();
    CompteTours = new tachometre();
    jaugeTemperature = new tempGauge();
    //CompteurKm =new kmCalculator();


    BootOpen= new LEDS(250,150,":/bootOpen_red.gif",235,0,0,130); //
    SeatBelt = new LEDS(280,0,":/seatBeltSign_red.gif",235,0,0,80); //pos OK
    VoyantBatterie = new LEDS(-90,110,":/battery.gif",235,0,0,90);
    BonnetOpen= new LEDS(400,150,":/bonnetOpen_red.gif",235,0,0,120);
    AirbagOn= new LEDS(50,0,":/airBag.gif",235,0,0,90); //pos ok
    FrontAntifog = new LEDS(-190,-260,":/frontFogLight.gif",235,0,0,100);
    RearAntifog= new LEDS(-20,-260,":/rearFogLight_blue.gif",235,0,0,100); //
    croisement = new LEDS(-100,-260,":/dayLight.gif",235,0,0,100);
    //Clignotant = new blinkingleds();
    OpenDoorBackLeftPassenger = new LEDS(-200,180,":/backLeftDoorOpen.gif",235,0,0,100);
    OpenDoorBackRightPassenger= new LEDS(-300,180,":/backrightDoorOpen.gif",235,0,0,100);
    OpenDoorFrontPassenger = new LEDS(0,180,":/frontRightDoorOpen.gif",235,0,0,100);
    OpenDoorDriver= new LEDS(100,180,":/driverDoorOpen.gif",235,0,0,100);

    handbrake= new LEDS(-600,150,":/hand_brake.png",235,0,0,80);





    Vitesse->setPos(200,0);
    CompteTours->setPos(-300,0);
    Essence->setPos(500,0);
    jaugeTemperature->setPos(-600,0);
    Clignotant->setPos(-300,0);
    CompteurKm->setPos(-300,0);



    this->addItem(Vitesse);
    this->addItem(CompteTours);
    this->addItem(Essence);
    this->addItem(jaugeTemperature);
    this->addItem(CompteurKm);
    SeatBelt->setZValue(10.0);
    RearAntifog->setZValue(10.0);
    this->addItem(SeatBelt);
    this->addItem(Clignotant);


    this->addItem(RearAntifog);
    this->addItem(BootOpen);
    this->addItem(BonnetOpen);
    this->addItem(AirbagOn);
    this->addItem(VoyantBatterie);
    this->addItem(FrontAntifog);
    this->addItem(croisement);


    //    this->addItem(adaptiveHeadLight);
    this->addItem(OpenDoorBackLeftPassenger);
    this->addItem(OpenDoorBackRightPassenger);
    this->addItem(OpenDoorDriver);
    this->addItem(OpenDoorFrontPassenger);
    this->addItem(handbrake);

}
