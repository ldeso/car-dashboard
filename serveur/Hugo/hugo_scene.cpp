#include "Hugo/hugo_scene.h"
#include "Hugo/hugo_mygraphicsitem.h"
#include "Hugo/hugo_compteur.h"
#include "Hugo/hugo_verre.h"
#include "Hugo/hugo_voyant.h"
#include <QDebug>
#include <QTimer>


hugo_scene::hugo_scene()


{


    CompteurKm=new hugo_MyGraphicsitem();
    this->addItem(CompteurKm);

    hugo_Compteur *compteur_vitesse=new hugo_Compteur;
    QStringList graduations_vitesse;
    graduations_vitesse<<"  0"<<" 20"<<" 40"<<" 60"<<" 80"<<"100"<<"120"<<"140"<<"160"<<"180"<<"200"<<"220";
    compteur_vitesse->Parametrage(0,0,90,210,-30,graduations_vitesse,0,64,128);
    this->addItem(compteur_vitesse);

    vitesse=new hugo_Aiguille;
    vitesse->parametrage(0,0,90,210,-30,220);
    vitesse->setValue(0);
    CompteurKm->current_speed=vitesse->getValue();
    this->addItem(vitesse);

    hugo_verre * verre_vitesse=new hugo_verre;
    verre_vitesse->parametrage(0,0,100,1);
    this->addItem(verre_vitesse);

    hugo_Compteur *compteur_rpm=new hugo_Compteur;
    QStringList graduations_rpm;
    graduations_rpm<<"  0"<<"  1"<<"  2"<<"  3"<<"  4"<<"  5"<<"  6"<<"  7"<<"  8";
    compteur_rpm->Parametrage(-170,20,80,210,60,graduations_rpm,0,64,128,5,120,0,0);
    this->addItem(compteur_rpm);

    CompteTours=new hugo_Aiguille;
    CompteTours->parametrage(-170,20,80,210,60,8000);
    CompteTours->angle=150;
    this->addItem(CompteTours);

    hugo_verre * verre_rpm=new hugo_verre;
    verre_rpm->parametrage(-170,20,81,1);
    this->addItem(verre_rpm);

    hugo_Compteur *Compteur_Essence=new hugo_Compteur;
    QStringList graduations_essence;
    graduations_essence<<"  E"<<"  F";
    Compteur_Essence->Parametrage(155,-60,40,-45,45,graduations_essence,0,64,128);
    this->addItem(Compteur_Essence);

    Essence=new hugo_Aiguille;
    Essence->parametrage(155,-60,40,45,-45,100);
    Essence->angle=-45;
    this->addItem(Essence);

   hugo_verre *verre_essence=new hugo_verre;
    verre_essence->parametrage(155,-60,40,-1);
    this->addItem(verre_essence);

    hugo_Compteur *temperature=new hugo_Compteur;
    QStringList graduations_temperature;
    graduations_temperature<<"  C"<<"  H";
    temperature->Parametrage(160,30,40,-45,45,graduations_temperature,0,64,128);
    this->addItem(temperature);

    hugo_Aiguille *aiguille_temperature=new hugo_Aiguille;
    aiguille_temperature->parametrage(160,30,40,45,-45,100);
    aiguille_temperature->angle=45;
    this->addItem(aiguille_temperature);

    hugo_verre *verre_temp=new hugo_verre;
     verre_temp->parametrage(160,30,40,-1);
     this->addItem(verre_temp);

    VoyantBatterie=new hugo_voyant;
    VoyantBatterie->parametrage(-180,50,"/home/utilisateur/Images/voyant-batterie-.gif");
    this->addItem(VoyantBatterie);

    hugo_voyant *ABS=new hugo_voyant;
    ABS->parametrage(-150,25,"/home/utilisateur/Images/voyant-abs.gif");
    this->addItem(ABS);

    hugo_voyant *liq_refroidissement=new hugo_voyant;
    liq_refroidissement->parametrage(200,-20,"/home/utilisateur/Images/voyant-ldr-liquide-refroidissement.gif");
    this->addItem(liq_refroidissement);

    hugo_voyant *liq_frein=new hugo_voyant;
    liq_frein->parametrage(-150,50,"/home/utilisateur/Images/voyant-liquide-frein.gif");
    this->addItem(liq_frein);

    hugo_voyant *plaquettes=new hugo_voyant;
    plaquettes->parametrage(-120,50,"/home/utilisateur/Images/voyant-plaquettes.gif");
    this->addItem(plaquettes);

    hugo_voyant *portieres=new hugo_voyant;
    portieres->parametrage(-200,75,"/home/utilisateur/Images/portieres.jpg");
    this->addItem(portieres);


    hugo_voyant *ceinture=new hugo_voyant;
    ceinture->parametrage(-170,75,"/home/utilisateur/Images/ceinture.jpg");
    this->addItem(ceinture);


    hugo_voyant *airbag=new hugo_voyant;
    airbag->parametrage(-140,75,"/home/utilisateur/Images/voyant-airbag.gif");
    this->addItem(airbag);

    hugo_voyant *huile=new hugo_voyant;
    huile->parametrage(-110,75,"/home/utilisateur/Images/voyant-huile-orange.jpg","/home/utilisateur/Images/voyant-huile-rouge.jpg");
    this->addItem(huile);

    hugo_voyant *clign_gauche=new hugo_voyant;
    clign_gauche->parametrage(-112,-90,"/home/utilisateur/Images/clign-gauche.jpg","a",0,255,0);
    this->addItem(clign_gauche);

    VoyantClignotantDroit=new hugo_voyant;
    VoyantClignotantDroit->parametrage(80,-91,"/home/utilisateur/Images/clign-droit.jpg","a",0,255,0);
    this->addItem(VoyantClignotantDroit);

}

