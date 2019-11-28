#include "Hugo/hugo_scene.h"
#include "Hugo/hugo_mygraphicsitem.h"
#include "Hugo/hugo_compteur.h"
#include <QDebug>
#include <QTimer>


hugo_scene::hugo_scene(scene_globale *parent):scene_globale(parent)
{
    ///Création de la scène de fond
    CompteurKm=new hugo_MyGraphicsitem();
    this->addItem(CompteurKm);

    ///Déclaration et paramétrage de tous les compteurs
    QStringList graduations_vitesse;
    graduations_vitesse<<"  0"<<" 20"<<" 40"<<" 60"<<" 80"<<"100"<<"120"<<"140"<<"160"<<"180"<<"200"<<"220";
    Vitesse=new hugo_Compteur(0,0,90,210,-30,graduations_vitesse,220,100,1,0,64,128);
    Vitesse->setValue(0);
    this->addItem(Vitesse);

    QStringList graduations_rpm;
    graduations_rpm<<"  0"<<"  1"<<"  2"<<"  3"<<"  4"<<"  5"<<"  6"<<"  7"<<"  8";
    CompteTours=new hugo_Compteur(-170,20,80,210,60,graduations_rpm,8000,80,1,0,64,128,5,120,0,0);
    CompteTours->setValue(0);
    this->addItem(CompteTours);

    QStringList graduations_essence;
    graduations_essence<<"  E"<<"  F";
    Essence=new hugo_Compteur(155,-60,40,-45,45,graduations_essence,100,40,-1,0,64,128);
    Essence->setValue(100);
    this->addItem(Essence);

    QStringList graduations_temperature;
    graduations_temperature<<"  C"<<"  H";
    jaugeTemperature=new hugo_Compteur(160,30,40,-45,45,graduations_temperature,100,40,-1,0,64,128);
    jaugeTemperature->setValue(0);
    this->addItem(jaugeTemperature);



    ///Déclaration et paramétrages de tous les voyants simples
    ///
    VoyantBatterie=new hugo_voyants_simples(-180,50,":/Images/voyant-batterie.gif");
    VoyantBatterie->setValue(0);
    this->addItem(VoyantBatterie);

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

    portieres=new hugo_voyants_simples;
    portieres->parametrage(-200,75,":/Images/portieres.jpg");
    this->addItem(portieres);

    ceinture=new hugo_voyants_simples;
    ceinture->parametrage(-170,75,":/Images/ceinture.jpg");
    this->addItem(ceinture);

    airbag=new hugo_voyants_simples;
    airbag->parametrage(-140,75,":/Images/voyant-airbag.gif");
    this->addItem(airbag);

    huile=new hugo_voyants_simples;
    huile->parametrage(-110,75,":/Images/voyant-huile-orange.jpg");
    this->addItem(huile);*/

    //Déclaration des clignotants
    Clignotant = new hugo_voyants_clignotant;
    this->addItem(Clignotant);

}

