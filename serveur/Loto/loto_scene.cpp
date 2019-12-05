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
    this->setBackgroundBrush(QBrush(Qt::black));

    Vitesse = new loto_dashboard();


    Essence = new fuel_guage();

    CompteTours = new tachometre();

    jaugeTemperature = new tempGauge();

        BootOpen= new LEDS(150,-100,":/bootOpen_red.gif",235,0,0,40); //
        SeatBelt = new LEDS(30,60,":/seatBeltSign_red.gif",235,0,0,40); //pos OK
        RearAntifog= new LEDS(-130,-100,":/rearFogLight_blue.gif",235,0,0,40); //pos ok
        VoyantBatterie = new LEDS(-130,100,":/battery.gif",235,0,0,40);
        BonnetOpen= new LEDS(-200,-100,":/bonnetOpen_red.gif",235,0,0,40);
        AirbagOn= new LEDS(130,-100,":/airBag.gif",235,0,0,40);




    // Ici on ajoute les voyants qui fait ON/OFF




        FrontAntifog = new LEDS(-150,-160,":/frontFogLight.gif",235,0,0,40);
        croisement = new LEDS(-100,-600,":/dayLight.gif",235,0,0,40);
        Clignotant = new LEDS(-150,-200,":/turnRight.gif",235,0,0,40);

        OpenDoorBackLeftPassenger = new LEDS(-130,-100,":/backLeftDoorOpen.gif",235,0,0,60);
        OpenDoorBackRightPassenger= new LEDS(-100,-600,":/backRightDoorOpen.gif",235,0,0,60);
        OpenDoorFrontPassenger = new LEDS(-130,-100,":/backLeftDoorOpen.gif",235,0,0,60);
        OpenDoorDriver= new LEDS(-100,-600,":/backRightDoorOpen.gif",235,0,0,60);

//        fourWheelDrive = new LEDS(-130,-100,":/4WD_red.gif",235,0,0,60);
//        allWheelDrive = new LEDS(-100,-600,":/AWD_red.gif",235,0,0,60);





    Vitesse->setPos(50,0);
    CompteTours->setPos(-250,0);
    Essence->setPos(225,50);
    jaugeTemperature->setPos(-400,50);



    this->addItem(Vitesse);
    this->addItem(CompteTours);
    this->addItem(Essence);
    this->addItem(jaugeTemperature);
    SeatBelt->setZValue(10.0);
    RearAntifog->setZValue(10.0);
    this->addItem(SeatBelt);


    this->addItem(RearAntifog);
    this->addItem(BootOpen);
    this->addItem(BonnetOpen);
    this->addItem(AirbagOn);
    this->addItem(VoyantBatterie);
    this->addItem(FrontAntifog);
    this->addItem(croisement);

//    this->addItem(turnLeft);
//    this->addItem(turnRight);
//    this->addItem(adaptiveHeadLight);
//    this->addItem(OpenDoorBackLeftPassenger);
//    this->addItem(OpenDoorBackRightPassenger);
//    this->addItem(OpenDoorDriver);
//    this->addItem(OpenDoorFrontPassenger);
//    this->addItem(allWheelDrive);
//    this->addItem(fourWheelDrive);

}
