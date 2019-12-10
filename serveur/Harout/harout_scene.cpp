#include "harout_scene.h"
#include <QStringList>
#include "cadran.h"
#include "harc.h"
#include "hvoyant.h"
#include "hvoyantwarning.h"
#include "hclignotant.h"
#include <QDebug>
#include <QTimer>

harout_scene::harout_scene()
{
    this->setBackgroundBrush(Qt::gray);

    QStringList gradVitesse;
    gradVitesse<<"  220"<<" 200"<<" 180"<<" 160"<<" 140"<<"120"<<"100"<<"80"<<"60"<<"40"<<"20"<<"0";
    QString Vtext = "Km/h";
    float angledVitesse = 0;

    QString Essencetext1 = "";

    Vitesse = new cadran(gradVitesse,Vtext, "",angledVitesse,220);
    this->addItem(Vitesse);
    //Vitesse->setPos(0,0);

    QStringList gradRPM;
    gradRPM<<"8"<<"7"<<"6"<<"5"<<"4"<<"3"<<"2"<<"1"<<"0";
    QString RPMtext {"x1000 RPM"};
    QString Temptext1 = "T°C";
    float valueRPM = 6;
    CompteTours= new cadran(gradRPM, RPMtext, Temptext1,valueRPM,8000);
    this->addItem(CompteTours);
    CompteTours->setPos(271,0);

    //int spanAngle0Essence = 0 *16;
    Essence =new Harc(0 ,120,"essence");
    this->addItem(Essence);
    //Essence->setPos(100,0);

    //int spanAngle0Temp = 0 *16;
    jaugeTemperature =new Harc(0,120,"temperature");
    this->addItem(jaugeTemperature);
    jaugeTemperature->setPos(271,0);

    //Voyant feux de position*
    position=new hvoyant(250,250,"://voyants-_warning.jpg",0,150,0);
    this->addItem(position);

    //Voyant feux de croisement*
    croisement=new hvoyant(280,250,"://voyant_feux_croisement.jpg",0,150,0);
    this->addItem(croisement);

    //Voyant feux de route*
    route=new hvoyant(220,250,"://voyant_feux_croisement.jpg",0,0,150);
    this->addItem(route);

    //*
    FrontAntifog=new hvoyant(-45,250,"://brouillard_avant.jpeg",0,150,0);
    this->addItem(FrontAntifog);

    //*
    RearAntifog=new hvoyant(500,250,"://brouillard_arriere.jpeg");
    this->addItem(RearAntifog);





    //    //Création de l'affichage de l'heure et du compteur km
    //    CompteurKm=new hugo_ecran;
    //    this->addItem(CompteurKm);

    //    //Jauge essence
    //        QStringList graduations_essence;
    //        graduations_essence<<"  E"<<"  F";
    //        Essence=new hugo_Compteur(155,-60,40,-45,45,graduations_essence,100,40,-1,0,64,128);
    //        Essence->setValue(100);
    //        this->addItem(Essence);

    //        //Jauge température huile moteur
    //        QStringList graduations_temperature;
    //        graduations_temperature<<"  C"<<"  H";
    //        jaugeTemperature=new hugo_Compteur(160,30,40,-45,45,graduations_temperature,100,40,-1,0,64,128);
    //        jaugeTemperature->setValue(0);
    //        this->addItem(jaugeTemperature);

    //        //Transmissions boite auto
    //        AutomaticTransmissionMode=new hugo_boite_vitesse;
    //        addItem(AutomaticTransmissionMode);

    //Voyant en cas de problème avec la batterie*
    VoyantBatterie=new hvoyant(-45,150,"://voyant-batterie.gif");
    this->addItem(VoyantBatterie);

    //Voyant suspensions*
    AdaptiveSuspensionDampers=new hvoyant(-45,120,"://asd.jpeg");
    this->addItem(AdaptiveSuspensionDampers);

    //Voyant ceinture non attachée*
    SeatBelt=new hvoyant(-45,90,"://ceinture.jpg");
    this->addItem(SeatBelt);

    //Voyant chauffage vitre arrière*
    RearWindowHeating=new hvoyant(-15,250,"://rear_window_heating.jpg",0,120,0);
    this->addItem(RearWindowHeating);

    //Voyant problème moteur*
    CheckEngine=new hvoyant(-45,0,"://check_engine.jpg");
    this->addItem(CheckEngine);

    //Voyants pour les portières --> Tous les signaux donnent le même voyant
    OpenDoorDriver=new hvoyant(-45,30,"://portieres.jpg");
    this->addItem(OpenDoorDriver);
    OpenDoorFrontPassenger =new hvoyant(-45,30,"://portieres.jpg");
    this->addItem(OpenDoorFrontPassenger);
    OpenDoorBackLeftPassenger=new hvoyant(-45,30,"://portieres.jpg");
    this->addItem(OpenDoorBackLeftPassenger);
    OpenDoorBackRightPassenger=new hvoyant(-45,30,"://portieres.jpg");
    this->addItem(OpenDoorBackRightPassenger);

    //*
    AirbagOn=new hvoyant(-45,60,"://voyant-airbag.gif");
    this->addItem(AirbagOn);

    //*
    objet_virtuel *VoyantEssenceFixe=new hvoyant(120,190,"://voyant_carburant.jpg",150,150,150,17);
    VoyantEssenceFixe->setValue(1);
    this->addItem(VoyantEssenceFixe);

//    ABS=new hvoyant;
//    ABS->parametrage(-150,25,"://voyant-abs");
//    this->addItem(ABS);

//    liq_refroidissement=new hvoyant;
//    liq_refroidissement->parametrage(200,-20,"://oyant-ldr-liquide-refroidissement.gif");
//    this->addItem(liq_refroidissement);

//    liq_frein=new hvoyant;
//    liq_frein->parametrage(-150,50,"://voyant-liquide-frein.gif");
//    this->addItem(liq_frein);

//    plaquettes=new hugo_voyants_simples;
//    plaquettes->parametrage(-120,50,"://voyant-plaquettes.gif");
//    this->addItem(plaquettes);

//    huile=new hvoyant;
//    huile->parametrage(-110,75,"://voyant-huile-orange.jpg");
//    this->addItem(huile);

    //Clignotants
    Clignotant = new hclignotant();
    this->addItem(Clignotant);

    //Warnings
    warning=new hvoyantwarning;
    warning->setValue(0);
    this->addItem(warning);


}
