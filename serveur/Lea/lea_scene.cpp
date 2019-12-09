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
//    QPixmap texture_fond (":/Effets/Icones_Voyants/orig_484482.jpg");
//    QPixmap voyant2= texture_fond.scaled(1300,600);
//    this->addPixmap(voyant2);
    this->setBackgroundBrush(Qt::black);

    QFontDatabase::addApplicationFont(":/Lea/Seven Segment.ttf");

    fond = new lea_SceneDeFond;
    this->addItem(fond);

    Vitesse = new speedometer_Lea(600.0,200.0,160.0,225,270,220);
    Vitesse->setZValue(1.0);
    this->addItem(Vitesse);

    Essence= new FuelGauge_lea(850,250,25,100);
    Essence->setZValue(1.0);
    this->addItem(Essence);

    CompteTours = new TachometerGauge_Lea(340.0,240.0,130.0,230,180,41,6000);
    CompteTours->setZValue(1.0);
    this->addItem(CompteTours);

    jaugeTemperature = new jauge_temperature_lea(800.0,200.0,90.0,120,120,130);
    jaugeTemperature->setZValue(1.0);
    this->addItem(jaugeTemperature);

    CompteurKm = new Compteur_kilometre_lea(530,300);
    this->addItem(CompteurKm);

    OpenDoorBackRightPassenger = new voyant_Lea(520,400,":/Lea/PorteOuvertePassagerD.png",80,80,Qt::transparent);
    this->addItem(OpenDoorBackRightPassenger);

    OpenDoorBackLeftPassenger = new voyant_Lea(520,400,":/Lea/PorteOuvertePassagerG.png",80,80,Qt::transparent);
    this->addItem(OpenDoorBackLeftPassenger);

    OpenDoorFrontPassenger = new voyant_Lea(520,400,":/Lea/PorteOuverte.png",80,80,Qt::transparent);
    this->addItem(OpenDoorFrontPassenger);

    OpenDoorDriver = new voyant_Lea(520,400,":/Lea/PorteOuverteConducteur.png",80,80,Qt::transparent);
    this->addItem(OpenDoorDriver);

    Clignotant = new lea_clignottants;
    this->addItem(Clignotant);

    handbrake = new voyant_Lea(520,180,":/Lea/Icones_Voyants/brake_warning.gif",50,50,Qt::red);
    this->addItem(handbrake);

    VoyantBatterie = new voyant_Lea(350,250,":/Lea/Icones_Voyants/battery.gif",50,50,Qt::red);
    this->addItem(VoyantBatterie);

    SeatBelt = new voyant_Lea(385,430,":/Lea/Icones_Voyants/seatBeltSign_red.gif",40,40,Qt::red);
    this->addItem(SeatBelt);

//    objet_virtuel *Oil = new voyant_Lea(360,430,":/Lea/Oil.png",50,50);
//    this->addItem(Oil);

    RearWindowHeating = new voyant_Lea(330,430,":/Lea/Icones_Voyants/rearWindowHeating_yellow.gif",40,40,(Qt::yellow));
    this->addItem(RearWindowHeating);

    ABS = new voyant_Lea(630,210,":/Lea/Icones_Voyants/ABS3.png",40,40,"#f87626");
    this->addItem(ABS);

    position = new voyant_Lea(630,420,":/Lea/Icones_Voyants/dayLight.gif",50,50,Qt::green);
    this->addItem(position);

    croisement =new voyant_Lea(630,420,":/Lea/Icones_Voyants/lowBeam.gif",50,50,Qt::green);
    this->addItem(croisement);

    route =new voyant_Lea(630,420,":/Lea/Icones_Voyants/highBeam.gif",50,50,Qt::blue);
    this->addItem(route);

    CruiseControlOn = new voyant_Lea (550,125,":/Lea/Icones_Voyants/Cruise_Control2.gif",50,50,Qt::green);
    this->addItem(CruiseControlOn);

    FrontAntifog = new voyant_Lea (690,420,":/Lea/Icones_Voyants/frontFogLight.gif",50,50,Qt::yellow);
    this->addItem(FrontAntifog);

    RearAntifog = new voyant_Lea (740,420,":/Lea/Icones_Voyants/rearFogLight_blue.gif",50,50,Qt::blue);
    this->addItem(RearAntifog);

    CheckEngine = new voyant_Lea (400,350,":/Lea/Icones_Voyants/checkEngine.gif",50,50,Qt::red);
    this->addItem(CheckEngine);

    AirbagOn= new voyant_Lea (720,350,":/Lea/Icones_Voyants/airBag.gif",50,50,Qt::red);
    this->addItem(AirbagOn);

    BootOpen = new voyant_Lea (440,400,":/Lea/Icones_Voyants/bootOpen_red.gif",50,50,Qt::red);
    this->addItem(BootOpen);

    BonnetOpen = new voyant_Lea (440,440,":/Lea/Icones_Voyants/bonnetOpen_red.gif",50,50,Qt::red);
    this->addItem(BonnetOpen);

    warning = new warning_lea (590,120,":/Lea/Icones_Voyants/hazardLights.gif",30,30);
    this->addItem(warning);

    AdaptiveSuspensionDampers = new voyant_Lea(0,0,"",30,30,Qt::transparent);

    AutomaticTransmissionMode = new voyant_Lea(0,0,"",30,30,Qt::transparent);

    AdaptiveCruiseControl = new voyant_Lea(0,0,"",30,30,Qt::transparent);

    OilTemp = new voyant_Lea(0,0,"",30,30,Qt::transparent);

    SpeedLimit = new voyant_Lea(0,0,"",30,30,Qt::transparent);

    oilLevel = new voyant_Lea(0,0,"",30,30,Qt::transparent);





}

