#include "Karim/karim_scene.h"
#include "Karim/voyants_karim.h"
#include "Karim/voyants_warning.h"

karim_scene::karim_scene()
{
    this->setSceneRect(-600,-300,1000,600);
    Vitesse=new CadranVitesse;
    CompteTours= new CadranTourParMin();
    Essence= new CadranEss();
    jaugeTemperature = new CadranEss();
    Clignotant = new clignot();
    VoyantBatterie = new Voyants_karim(":/Lea/Icones_Voyants/battery.gif",-50,0,50);
    position= new Voyants_karim(":/Lea/Icones_Voyants/dayLight.gif",-50,-80,50);
    croisement= new Voyants_karim(":/Lea/Icones_Voyants/lowBeam.gif",-50,-80,50);
    route= new Voyants_karim(":/Lea/Icones_Voyants/highBeam.gif",-50,-80,50);
    AirbagOn=new Voyants_karim(":/Lea/Icones_Voyants/airBag.gif",-190,-80,50);
    CheckEngine=new Voyants_karim(":/Images/check_engine.jpg",-115,-80,50);
    SeatBelt= new Voyants_karim(":/Lea/Icones_Voyants/seatBeltSign_red.gif",-115,0,40);
    OpenDoorDriver= new Voyants_karim(":/Lea/PorteOuverteConducteur.png",-190,0,50);
    OpenDoorBackLeftPassenger= new Voyants_karim(":/Lea/PorteOuvertePassagerG.png",-190,0,50);
    OpenDoorBackRightPassenger= new Voyants_karim(":/Lea/PorteOuvertePassagerD.png",-190,0,50);
    OpenDoorFrontPassenger= new Voyants_karim(":/Lea/PorteOuverte.png",-190,0,50);
    warning=new voyants_warning;
    warning->setValue(0);

    Vitesse->setPos(-400,100);
    CompteTours->setPos(200,100);
    Essence->setPos(50,-230);
    jaugeTemperature->setPos(340,-230);
    //Essence->setPos(-400,100);
    //jaugeTemperature->setPos(800,100);

    this->setBackgroundBrush(Qt::black);
    this->addItem(Vitesse);
    this->addItem(CompteTours);
    this->addItem(Essence);
    this->addItem(jaugeTemperature);
    this->addItem(Clignotant);
    this->addItem(VoyantBatterie);
    this->addItem(position);
    this->addItem(croisement);
    this->addItem(route);
    this->addItem(AirbagOn);
    this->addItem(CheckEngine);
    this->addItem(SeatBelt);
    this->addItem(OpenDoorDriver);
    this->addItem(OpenDoorBackLeftPassenger);
    this->addItem(OpenDoorBackRightPassenger);
    this->addItem(OpenDoorFrontPassenger);
    this->addItem(warning);

}
