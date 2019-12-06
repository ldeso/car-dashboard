#include "Karim/karim_scene.h"
#include "Karim/voyants.h"
#include "Karim/voyants_warning.h"

karim_scene::karim_scene()
{
    this->setSceneRect(-600,-300,1000,600);
    Vitesse=new CadranVitesse;
    CompteTours= new CadranTourParMin();
    Essence= new CadranEss();
    jaugeTemperature = new CadranEss();
    Clignotant = new clignot();
    VoyantBatterie = new Voyants(":/Lea/Icones_Voyants/battery.gif",-50,-20,50);
    position= new Voyants(":/Lea/Icones_Voyants/dayLight.gif",-50,-100,50);
    croisement= new Voyants(":/Lea/Icones_Voyants/lowBeam.gif",-50,-100,50);
    route= new Voyants(":/Lea/Icones_Voyants/highBeam.gif",-50,-100,50);
    AirbagOn=new Voyants(":/Lea/Icones_Voyants/airBag.gif",-200,-100,50);
    CheckEngine=new Voyants(":/Images/check_engine.jpg",-120,-100,50);
    SeatBelt= new Voyants(":/Lea/Icones_Voyants/seatBeltSign_red.gif",-120,-20,50);
    OpenDoorDriver= new Voyants(":/Lea/PorteOuverteConducteur.png",-200,-20,50);
    OpenDoorBackLeftPassenger= new Voyants(":/Lea/PorteOuvertePassagerG.png",-200,-20,50);
    OpenDoorBackRightPassenger= new Voyants(":/Lea/PorteOuvertePassagerD.png",-200,-20,50);
    OpenDoorFrontPassenger= new Voyants(":/Lea/PorteOuverte.png",-200,-20,50);
    warning=new voyants_warning;
    warning->setValue(0);

    Vitesse->setPos(-400,100);
    CompteTours->setPos(200,100);
    Essence->setPos(20,-250);
    jaugeTemperature->setPos(370,-250);
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
