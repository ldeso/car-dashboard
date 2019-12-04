#include "Karim/karim_scene.h"
#include "Karim/voyants.h"

karim_scene::karim_scene()
{
    Vitesse=new CadranVitesse;
    CompteTours= new CadranTourParMin();
    Essence= new CadranEss();
    jaugeTemperature = new CadranEss();
    Clignotant = new clignot();
    VoyantBatterie = new Voyants(":/Icones/batterie.jpg",-50,-20,50);
    position= new Voyants(":/Icones/antibrouillard.jpg",-50,-100,50);
    croisement= new Voyants(":/Icones/feucroisement.jpg",-200,-100,50);
    route= new Voyants(":/Icones/pleinphare.jpg",-120,-100,50);
    SeatBelt= new Voyants(":/Icones/ceinture.jpg",-120,-20,50);
    OpenDoorDriver= new Voyants(":/Icones/portouverte.jpg",-200,-20,50);
    OpenDoorBackLeftPassenger= new Voyants(":/Icones/portouverte.jpg",-200,-20,50);
    OpenDoorBackRightPassenger= new Voyants(":/Icones/portouverte.jpg",-200,-20,50);
    OpenDoorFrontPassenger= new Voyants(":/Icones/portouverte.jpg",-200,-20,50);

    Vitesse->setPos(-400,100);
    CompteTours->setPos(200,100);
    Essence->setPos(20,-250);
    jaugeTemperature->setPos(370,-250);

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
    this->addItem(SeatBelt);
    this->addItem(OpenDoorDriver);
    this->addItem(OpenDoorBackLeftPassenger);
    this->addItem(OpenDoorBackRightPassenger);
    this->addItem(OpenDoorFrontPassenger);

}
