#include "Hugo/hugo_scene.h"
#include "Hugo/hugo_mygraphicsitem.h"
#include "Hugo/hugo_compteur.h"
#include "Hugo/hugo_verre.h"
#include "Hugo/hugo_voyant.h"


hugo_scene::hugo_scene()
{
    hugo_MyGraphicsitem *background=new hugo_MyGraphicsitem();
    this->addItem(background);

    hugo_Compteur *compteur_vitesse=new hugo_Compteur;
    QStringList graduations_vitesse;
    graduations_vitesse<<"0"<<"20"<<"40"<<"60"<<"80"<<"100"<<"120"<<"140"<<"160"<<"180"<<"200"<<"220";
    compteur_vitesse->Parametrage(0,0,90,210,-30,graduations_vitesse,0,64,128);
    this->addItem(compteur_vitesse);

    vitesse=new hugo_Aiguille;
    vitesse->parametrage(0,0,90,210,-30,220);
    vitesse->setValue(0);
    this->addItem(vitesse);

    hugo_verre * verre_vitesse=new hugo_verre;
    verre_vitesse->parametrage(0,0,100);
    this->addItem(verre_vitesse);

    hugo_Compteur *compteur_rpm=new hugo_Compteur;
    QStringList graduations_rpm;
    graduations_rpm<<"0"<<"1"<<"2"<<"3"<<"4"<<"5"<<"6"<<"7"<<"8";
    compteur_rpm->Parametrage(-170,20,80,210,60,graduations_rpm,0,64,128,5,120,0,0);
    this->addItem(compteur_rpm);

    rpm=new hugo_Aiguille;
    rpm->parametrage(-170,20,80,210,60,8000);
    rpm->angle=150;
    this->addItem(rpm);

    hugo_verre * verre_rpm=new hugo_verre;
    verre_rpm->parametrage(-170,20,81);
    this->addItem(verre_rpm);

    hugo_Compteur *essence=new hugo_Compteur;
    QStringList graduations_essence;
    graduations_essence<<"E"<<"F";
    essence->Parametrage(140,-60,40,-45,45,graduations_essence,0,64,128);
    this->addItem(essence);

    hugo_Aiguille *aiguille_essence=new hugo_Aiguille;
    aiguille_essence->parametrage(140,-60,40,45,-45,100);
    aiguille_essence->angle=-45;
    this->addItem(aiguille_essence);

    hugo_Compteur *temperature=new hugo_Compteur;
    QStringList graduations_temperature;
    graduations_temperature<<"C"<<"H";
    temperature->Parametrage(160,30,40,-45,45,graduations_temperature,0,64,128);
    this->addItem(temperature);

    hugo_Aiguille *aiguille_temperature=new hugo_Aiguille;
    aiguille_temperature->parametrage(160,30,40,45,-45,100);
    aiguille_temperature->angle=45;
    this->addItem(aiguille_temperature);

    hugo_voyant *batterie=new hugo_voyant;
    batterie->parametrage(-180,50,"/home/utilisateur/Images/voyant-batterie-.gif","a",255,0,0);
    batterie->on=1;
    this->addItem(batterie);

    hugo_voyant *ABS=new hugo_voyant;
    ABS->parametrage(-150,25,"/home/utilisateur/Images/voyant-abs.gif");
    ABS->on=1;
    this->addItem(ABS);

    hugo_voyant *liq_refroidissement=new hugo_voyant;
    liq_refroidissement->parametrage(200,-20,"/home/utilisateur/Images/voyant-ldr-liquide-refroidissement.gif");
    liq_refroidissement->on=1;
    this->addItem(liq_refroidissement);

    hugo_voyant *liq_frein=new hugo_voyant;
    liq_frein->parametrage(-150,50,"/home/utilisateur/Images/voyant-liquide-frein.gif");
    liq_frein->on=1;
    this->addItem(liq_frein);

    hugo_voyant *plaquettes=new hugo_voyant;
    plaquettes->parametrage(-120,50,"/home/utilisateur/Images/voyant-plaquettes.gif");
    plaquettes->on=1;
    this->addItem(plaquettes);

    hugo_voyant *portieres=new hugo_voyant;
    portieres->parametrage(-200,75,"/home/utilisateur/Images/portieres.jpg");
    portieres->on=1;
    this->addItem(portieres);


    hugo_voyant *ceinture=new hugo_voyant;
    ceinture->parametrage(-170,75,"/home/utilisateur/Images/ceinture.jpg");
    ceinture->on=1;
    this->addItem(ceinture);


    hugo_voyant *airbag=new hugo_voyant;
    airbag->parametrage(-140,75,"/home/utilisateur/Images/voyant-airbag.gif");
    airbag->on=1;
    this->addItem(airbag);

    hugo_voyant *huile=new hugo_voyant;
    huile->parametrage(-110,75,"/home/utilisateur/Images/voyant-huile-orange.jpg","/home/utilisateur/Images/voyant-huile-rouge.jpg");
    huile->on=0;
    this->addItem(huile);

    hugo_voyant *clign_gauche=new hugo_voyant;
    clign_gauche->parametrage(-290,0,"/home/utilisateur/Images/clign-gauche.jpg","a",0,255,0);
    this->addItem(clign_gauche);
}
