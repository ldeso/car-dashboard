///
///\file hugo_scene.cpp
/// \brief Classe dérivée de scene_globale où sont ajoutés et paramétrés tous les composants du tableau de bord. Tous les objets doivent être définis au préalable dans scene_globale.h
///
#include "Hugo/hugo_scene.h"
#include "Hugo/hugo_mygraphicsitem.h"
#include "Hugo/hugo_compteur.h"
#include "hugo_ecran.h"
#include "hugo_voyant_warning.h"
#include "hugo_boite_vitesse.h"
#include <QDebug>
#include <QTimer>


hugo_scene::hugo_scene(scene_globale *parent):scene_globale(parent)
{
    //Création de la scène de fond
    hugo_MyGraphicsitem *background=new hugo_MyGraphicsitem();
    this->addItem(background);


    //Voyant feux de position
    position=new hugo_voyants_simples(15,-50,":/Images/voyant_feux_position.jpg",0,150,0);
    this->addItem(position);

    FrontAntifog=new hugo_voyants_simples(-43,-50,":/Images/brouillard_avant.jpeg",0,150,0);
    this->addItem(FrontAntifog);

    RearAntifog=new hugo_voyants_simples(-43,-21,":/Images/brouillard_arriere.jpeg");
    this->addItem(RearAntifog);

    //Voyant feux de croisement
    croisement=new hugo_voyants_simples(15,-22,":/Images/voyant_feux_croisement.jpg",0,150,0);
    this->addItem(croisement);

    //Voyant feux de route
    route=new hugo_voyants_simples(15,3,":/Images/voyant_feux_croisement.jpg",0,0,150);
    this->addItem(route);

    //Création de l'affichage de l'heure et du compteur km
    CompteurKm=new hugo_ecran;
    this->addItem(CompteurKm);

    //Compteur vitesse
    QStringList graduations_vitesse;
    graduations_vitesse<<"  0"<<" 20"<<" 40"<<" 60"<<" 80"<<"100"<<"120"<<"140"<<"160"<<"180"<<"200"<<"220";
    Vitesse=new hugo_Compteur(0,0,90,210,-30,graduations_vitesse,220,100,1,0,64,128);
    Vitesse->setValue(0);
    this->addItem(Vitesse);

    //Compte tours
    QStringList graduations_rpm;
    graduations_rpm<<"  0"<<"  1"<<"  2"<<"  3"<<"  4"<<"  5"<<"  6"<<"  7"<<"  8";
    CompteTours=new hugo_Compteur(-170,20,80,210,60,graduations_rpm,8000,80,1,0,64,128,5,120,0,0);
    CompteTours->setValue(0);
    this->addItem(CompteTours);

    //Jauge essence
    QStringList graduations_essence;
    graduations_essence<<"  E"<<"  F";
    Essence=new hugo_Compteur(155,-60,40,-45,45,graduations_essence,100,40,-1,0,64,128);
    Essence->setValue(100);
    this->addItem(Essence);

    //Jauge température huile moteur
    QStringList graduations_temperature;
    graduations_temperature<<"  C"<<"  H";
    jaugeTemperature=new hugo_Compteur(160,30,40,-45,45,graduations_temperature,100,40,-1,0,64,128);
    jaugeTemperature->setValue(0);
    this->addItem(jaugeTemperature);

    //Transmissions boite auto
    AutomaticTransmissionMode=new hugo_boite_vitesse;
    addItem(AutomaticTransmissionMode);

    //Voyant en cas de problème avec la batterie
    VoyantBatterie=new hugo_voyants_simples(-180,50,":/Images/voyant-batterie.gif");
    this->addItem(VoyantBatterie);

    //Voyant suspensions
    AdaptiveSuspensionDampers=new hugo_voyants_simples(210,50,":/Images/asd.jpeg");
    this->addItem(AdaptiveSuspensionDampers);

    //Voyant ceinture non attachée
    SeatBelt=new hugo_voyants_simples(-170,75,":/Images/ceinture.jpg");
    this->addItem(SeatBelt);

    //Voyant chauffage vitre arrière
    RearWindowHeating=new hugo_voyants_simples(210,20,":/Images/rear_window_heating.jpg",0,120,0);
    this->addItem(RearWindowHeating);

    //Voyant problème moteur
    CheckEngine=new hugo_voyants_simples(210,-7,":/Images/check_engine.jpg");
    this->addItem(CheckEngine);

    //Voyants pour les portières --> Tous les signaux donnent le même voyant
    OpenDoorDriver=new hugo_voyants_simples(-200,75,":/Images/portieres.jpg");
    this->addItem(OpenDoorDriver);
    OpenDoorFrontPassenger =new hugo_voyants_simples(-200,75,":/Images/portieres.jpg");
    this->addItem(OpenDoorFrontPassenger);
    OpenDoorBackLeftPassenger=new hugo_voyants_simples(-200,75,":/Images/portieres.jpg");
    this->addItem(OpenDoorBackLeftPassenger);
    OpenDoorBackRightPassenger=new hugo_voyants_simples(-200,75,":/Images/portieres.jpg");
    this->addItem(OpenDoorBackRightPassenger);


    AirbagOn=new hugo_voyants_simples(-140,75,":/Images/voyant-airbag.gif");
    this->addItem(AirbagOn);


 //   objet_virtuel *VoyantEssenceFixe=new hugo_voyants_simples(150,-100,":/Images/voyant_carburant.jpg",150,150,150,17);
   // VoyantEssenceFixe->setValue(1);
    //this->addItem(VoyantEssenceFixe);

    /*ABS=new hugo_voyants_simples;
    ABS->parametrage(-150,25,":/Images/voyant-abs");
    this->addItem(ABS);

    liq_refroidissement=new hugo_voyants_simples;
    liq_refroidissement->parametrage(200,-20,":/Images/oyant-ldr-liquide-refroidissement.gif");
    this->addItem(liq_refroidissement);

    liq_frein=new hugo_voyants_simples;
    liq_frein->parametrage(-150,50,":/Images/voyant-liquide-frein.gif");
    this->addItem(liq_frein);

    plaquettes=new hugo_voyants_simples;
    plaquettes->parametrage(-120,50,":/Images/voyant-plaquettes.gif");
    this->addItem(plaquettes);



    huile=new hugo_voyants_simples;
    huile->parametrage(-110,75,":/Images/voyant-huile-orange.jpg");
    this->addItem(huile);*/

    //Clignotants
    Clignotant = new hugo_voyants_clignotant;
    this->addItem(Clignotant);

    //Warnings
    warning=new hugo_voyant_warning;
    warning->setValue(0);
    this->addItem(warning);


}

