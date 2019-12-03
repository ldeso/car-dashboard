#include "Karim/karim_scene.h"

karim_scene::karim_scene()
{
    Vitesse=new CadranVitesse;
    CompteTours= new CadranTourParMin();
    Essence= new CadranEss();
    Temperature = new CadranEss();
    Clignotant = new clignot();

    VoyantBatterie = new Voyant_batterie();

    Vitesse->setPos(-400,100);
    CompteTours->setPos(200,100);
    Essence->setPos(20,-250);
    Temperature->setPos(370,-250);

    this->setBackgroundBrush(Qt::black);
    this->addItem(Vitesse);
    this->addItem(CompteTours);
    this->addItem(Essence);
    this->addItem(Temperature);
    this->addItem(Clignotant);
    this->addItem(VoyantBatterie);

}
