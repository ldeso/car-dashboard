///
///\file lea_scene.cpp
/// \brief Classe dérivée de scene_globale où sont ajoutés et paramétrés tous les composants du tableau de bord. Tous les objets doivent être définis au préalable dans scene_globale.h
///



#include "lea_scene.h"
#include <QFontDatabase>
#include <QPainter>
#include <QDebug>
#include "mainwindow.h"

Lea_scene::Lea_scene(scene_globale *parent):scene_globale(parent)
{
    QPixmap texture_fond (":/Effets/Icones_Voyants/orig_484482.jpg");
    QPixmap voyant2= texture_fond.scaled(1300,600);
    this->addPixmap(voyant2);

    QFontDatabase::addApplicationFont(":/Lea/Seven Segment.ttf");

    fond = new lea_SceneDeFond;
    this->addItem(fond);

    Vitesse = new speedometer_Lea(600.0,200.0,160.0,225,-270,270,220);
 //   Vitesse->setValue(0);
    Vitesse->setZValue(1.0);
    this->addItem(Vitesse);

    Essence= new FuelGauge_lea(850,250,25,100,825,350,825,250);
//    Essence->setValue(40);
    Essence->setZValue(1.0);
    this->addItem(Essence);

    CompteTours = new TachometerGauge_Lea(340.0,240.0,130.0,230,50,180,41,6000);
 //   CompteTours->setValue(0);
    CompteTours->setZValue(1.0);
    this->addItem(CompteTours);

    CompteurKm = new Compteur_kilometre_lea(600,200);
    this->addItem(CompteurKm);

    OpenDoorBackRightPassenger = new voyant_Lea(520,400,":/Lea/PorteOuvertePassagerD.png",80,80);
    this->addItem(OpenDoorBackRightPassenger);

    OpenDoorBackLeftPassenger = new voyant_Lea(520,400,":/Lea/PorteOuvertePassagerG.png",80,80);
    this->addItem(OpenDoorBackLeftPassenger);

    OpenDoorFrontPassenger = new voyant_Lea(520,400,":/Lea/PorteOuverte.png",80,80);
    this->addItem(OpenDoorFrontPassenger);

    OpenDoorDriver = new voyant_Lea(520,400,":/Lea/PorteOuverteConducteur.png",80,80);
    this->addItem(OpenDoorDriver);

    Clignotant = new lea_clignottants;
    this->addItem(Clignotant);

    voyant_Lea *handbrakeOn = new voyant_Lea(520,430,":/Lea/Icones_Voyants/brake_warning.gif",50,50);
    this->addItem(handbrakeOn);

    VoyantBatterie = new voyant_Lea(560,350,":/Lea/Icones_Voyants/battery.gif",50,50);
    this->addItem(VoyantBatterie);

    SeatBelt = new voyant_Lea(385,430,":/Lea/Icones_Voyants/seatBeltSign_red.gif",40,40);
    this->addItem(SeatBelt);

    objet_virtuel *Oil = new voyant_Lea(360,430,":/Lea/Oil.png",50,50);
    this->addItem(Oil);

    position = new voyant_Lea(630,420,":/Lea/Icones_Voyants/dayLight.gif",50,50);
    this->addItem(position);

    croisement =new voyant_Lea(630,420,":/Lea/Icones_Voyants/lowBeam.gif",50,50);
    this->addItem(croisement);

    route =new voyant_Lea(630,420,":/Lea/Icones_Voyants/highBeam.gif",50,50);
    this->addItem(route);

    CruiseControlOn = new voyant_Lea (550,125,":/Lea/Icones_Voyants/Cruise_Control.gif",50,50);
    this->addItem(CruiseControlOn);

    FrontAntifog = new voyant_Lea (690,420,":/Lea/Icones_Voyants/frontFogLight.gif",50,50);
    this->addItem(FrontAntifog);

    RearAntifog = new voyant_Lea (740,420,":/Lea/Icones_Voyants/rearFogLight_blue.gif",50,50);
    this->addItem(RearAntifog);

    CheckEngine = new voyant_Lea (400,350,":/Lea/Icones_Voyants/checkEngine.gif",50,50);
    this->addItem(CheckEngine);

    AirbagOn= new voyant_Lea (720,350,":/Lea/Icones_Voyants/airBag.gif",50,50);
    this->addItem(AirbagOn);

    BootOpen = new voyant_Lea (400,400,":/Lea/Icones_Voyants/bootOpen_red.gif",50,50);
    this->addItem(BootOpen);

    BonnetOpen = new voyant_Lea (400,440,":/Lea/Icones_Voyants/bonnetOpen_red.gif",50,50);
    this->addItem(BonnetOpen);

    warning = new warning_lea (590,120,":/Lea/Icones_Voyants/hazardLights.gif",30,30);
    this->addItem(warning);


}

