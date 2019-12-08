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
    CompteurKm =new kmCalculator();


        BootOpen= new LEDS(220,-130,":/bootOpen_red.gif",235,0,0,80); //
        SeatBelt = new LEDS(300,0,":/seatBeltSign_red.gif",235,0,0,80); //pos OK
        VoyantBatterie = new LEDS(-100,110,":/battery.gif",235,0,0,80);
        BonnetOpen= new LEDS(130,-130,":/bonnetOpen_red.gif",235,0,0,80);
        AirbagOn= new LEDS(50,0,":/airBag.gif",235,0,0,70); //pos ok


        FrontAntifog = new LEDS(-190,-260,":/frontFogLight.gif",235,0,0,100);
        RearAntifog= new LEDS(-20,-260,":/rearFogLight_blue.gif",235,0,0,100); //
        croisement = new LEDS(-100,-260,":/dayLight.gif",235,0,0,100);
        Clignotant = new blinkingleds();



//            for (int i = 1000;i >= -1000; i-=100)
//            {
//                for (int j = 1000;j >= -1000; j-=100)
//                {
//                    QPainter * painter;
//                    painter->setPen(QPen(QBrush("white"),10,Qt::SolidLine, Qt::SquareCap));
//                    QFont displayFont("Helvetica");
//                    displayFont.setPointSize(8);
//                    painter->setFont(displayFont);
//                    painter->drawText(i,j,QString("*%1,%2").arg(i).arg(j));

//                }
//            }


    // Ici on ajoute les voyants qui fait ON/OFF





        OpenDoorBackLeftPassenger = new LEDS(-130,-100,":/backLeftDoorOpen.gif",235,0,0,60);
        OpenDoorBackRightPassenger= new LEDS(-100,-600,":/backRightDoorOpen.gif",235,0,0,60);
        OpenDoorFrontPassenger = new LEDS(-130,-100,":/backLeftDoorOpen.gif",235,0,0,60);
        OpenDoorDriver= new LEDS(-100,-600,":/backRightDoorOpen.gif",235,0,0,60);

//        fourWheelDrive = new LEDS(-130,-100,":/4WD_red.gif",235,0,0,60);
//        allWheelDrive = new LEDS(-100,-600,":/AWD_red.gif",235,0,0,60);





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
