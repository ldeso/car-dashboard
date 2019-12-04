#include "lea_scene.h"
#include <QFontDatabase>
#include <QPainter>
#include <QDebug>
#include "mainwindow.h"

Lea_scene::Lea_scene(scene_globale *parent):scene_globale(parent)
{//QPainter *painter = new QPainter;





    QPixmap texture_fond (":/Effets/Icones_Voyants/orig_484482.jpg");
    QPixmap voyant2= texture_fond.scaled(1300,600);
   // qDebug()<<w.width() <<w.height();
    //QBrush brush(texture_fond);
    //brush.setTexture(voyant2);
    this->addPixmap(voyant2);

    //this->setBackgroundBrush(brush);
    QFontDatabase::addApplicationFont(":/Lea/Seven Segment.ttf");

    fond = new lea_SceneDeFond;
    this->addItem(fond);

    Vitesse = new speedometer_Lea(600.0,200.0,160.0,225,-270,270,220);
    Vitesse->setValue(0);
    this->addItem(Vitesse);

//    deux_voyants_lea *fuel = new deux_voyants_lea;
//    fuel->parametrage(580,320,":/Icones_Voyants/fuel.png",":/Icones_Voyants/fuel2.png");
//    fuel->setSize(30,30);
//    fuel->on=1;
//    this->addItem(fuel);

    Essence= new FuelGauge_lea(850,250,25,100,825,350,825,250);
    Essence->setValue(40);
    this->addItem(Essence);

    CompteTours = new TachometerGauge_Lea(340.0,240.0,130.0,230,50,180,41,6000);
    CompteTours->setValue(0);
    this->addItem(CompteTours);

    OpenDoorBackRightPassenger = new voyant_Lea(580,400,":/Lea/PorteOuvertePassagerD.png",80,80);
    this->addItem(OpenDoorBackRightPassenger);

    OpenDoorBackLeftPassenger = new voyant_Lea(580,400,":/Lea/PorteOuvertePassagerG.png",80,80);
    this->addItem(OpenDoorBackLeftPassenger);

    OpenDoorFrontPassenger = new voyant_Lea(580,400,":/Lea/PorteOuverte.png",80,80);
    this->addItem(OpenDoorFrontPassenger);

    OpenDoorDriver = new voyant_Lea(580,400,":/Lea/PorteOuverteConducteur.png",80,80);
    this->addItem(OpenDoorDriver);

    Clignotant = new lea_clignottants;
    this->addItem(Clignotant);

    voyant_Lea *handbrakeOn = new voyant_Lea(520,430,":/Lea/Icones_Voyants/brake_warning.gif",50,50);
    this->addItem(handbrakeOn);

    VoyantBatterie = new voyant_Lea(560,430,":/Lea/Icones_Voyants/battery.gif",50,50);
    this->addItem(VoyantBatterie);

    SeatBelt = new voyant_Lea(415,440,":/Lea/Icones_Voyants/seatBeltSign_red.gif",35,35);
    this->addItem(SeatBelt);

    objet_virtuel *Oil = new voyant_Lea(360,430,":/Lea/Oil.png",50,50);
    this->addItem(Oil);

    position = new voyant_Lea(660,430,":/Lea/Icones_Voyants/dayLight.gif",50,50);
    this->addItem(position);

    croisement =new voyant_Lea(660,430,":/Lea/Icones_Voyants/lowBeam.gif",50,50);
    this->addItem(croisement);

    route =new voyant_Lea(660,430,":/Lea/Icones_Voyants/highBeam.gif",50,50);
    this->addItem(route);

    CruiseControlOn = new voyant_Lea (600,245,":/Lea/Icones_Voyants/Cruise_Control.gif",30,30);
    this->addItem(CruiseControlOn);

    FrontAntifog = new voyant_Lea (720,430,":/Lea/Icones_Voyants/frontFogLight.gif",50,50);
    this->addItem(FrontAntifog);

    RearAntifog = new voyant_Lea (770,430,":/Lea/Icones_Voyants/rearFogLight_blue.gif",50,50);
    this->addItem(RearAntifog);



}

