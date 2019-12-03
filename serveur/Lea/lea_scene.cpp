#include "lea_scene.h"
#include <QFontDatabase>

Lea_scene::Lea_scene(scene_globale *parent):scene_globale(parent)
{
    this->setBackgroundBrush(QBrush(Qt::black));
    QFontDatabase::addApplicationFont(":/Lea/Seven Segment.ttf");

    Vitesse = new speedometer_Lea(400.0,200.0,160.0,225,-270,270,220);
    Vitesse->setValue(0);
    this->addItem(Vitesse);

//    deux_voyants_lea *fuel = new deux_voyants_lea;
//    fuel->parametrage(580,320,":/Icones_Voyants/fuel.png",":/Icones_Voyants/fuel2.png");
//    fuel->setSize(30,30);
//    fuel->on=1;
//    this->addItem(fuel);

    Essence= new FuelGauge_lea(650,250,25,100,625,350,625,250);
    Essence->setValue(40);
    this->addItem(Essence);

    CompteTours = new TachometerGauge_Lea(140.0,240.0,130.0,230,50,180,41,6000);
    CompteTours->setValue(0);
    this->addItem(CompteTours);

    OpenDoorBackRightPassenger = new voyant_Lea(380,400,":/Lea/PorteOuvertePassagerD.png",80,80);
    this->addItem(OpenDoorBackRightPassenger);

    OpenDoorBackLeftPassenger = new voyant_Lea(380,400,":/Lea/PorteOuvertePassagerG.png",80,80);
    this->addItem(OpenDoorBackLeftPassenger);

    OpenDoorFrontPassenger = new voyant_Lea(380,400,":/Lea/PorteOuverte.png",80,80);
    this->addItem(OpenDoorFrontPassenger);

    OpenDoorDriver = new voyant_Lea(380,400,":/Lea/PorteOuverteConducteur.png",80,80);
    this->addItem(OpenDoorDriver);

    Clignotant = new lea_clignottants;
    this->addItem(Clignotant);

    voyant_Lea *handbrakeOn = new voyant_Lea(320,430,":/Lea/Icones_Voyants/hand_brake.png",50,50);
    this->addItem(handbrakeOn);

    VoyantBatterie = new voyant_Lea(260,430,":/Lea/Icones_Voyants/battery.gif",50,50);
    this->addItem(VoyantBatterie);

    SeatBelt = new voyant_Lea(215,440,":/Lea/Icones_Voyants/seatBeltSign_red.gif",35,35);
    this->addItem(SeatBelt);

    objet_virtuel *Oil = new voyant_Lea(160,430,":/Lea/Oil.png",50,50);
    this->addItem(Oil);

    position = new voyant_Lea(460,430,":/Lea/Icones_Voyants/dayLight.gif",50,50);
    this->addItem(position);

    croisement =new voyant_Lea(460,430,":/Lea/Icones_Voyants/lowBeam.gif",50,50);
    this->addItem(croisement);

    route =new voyant_Lea(460,430,":/Lea/Icones_Voyants/highBeam.gif",50,50);
    this->addItem(route);

    CruiseControlOn = new voyant_Lea (400,300,":/Lea/Icones_Voyants/Cruise_Control.gif",30,30);
    this->addItem(CruiseControlOn);

    objet_virtuel *phares_brouillard_avant = new voyant_Lea(520,430,":/Lea/Icones_Voyants/frontFogLight.gif",50,50);
    this->addItem(phares_brouillard_avant);

    objet_virtuel *phares_brouillard_arriere = new voyant_Lea(570,430,":/Lea/Icones_Voyants/rearFogLight_blue.gif",50,50);
    this->addItem(phares_brouillard_arriere);







}

