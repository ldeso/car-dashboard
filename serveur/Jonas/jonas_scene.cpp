#include "jonas_scene.h"
#include "jonas_compteur.h"
#include "jonas_voyant_simple.h"
#include "jonas_voyant_clignotant.h"
#include "jonas_voyant_warning.h"
#include "jonas_compteurkm.h"
#include <QDebug>

Jonas_scene::Jonas_scene(scene_globale *parent) : scene_globale(parent)
{
    QStringList listFuel;
    QStringList listRpm;
    QStringList listTemp;
    for (int i=0; i<=8; i++) {
        listRpm << QString::number(i);
    }
    this->setBackgroundBrush(Qt::black);
    this->setSceneRect(-300,-200,580,400);
    listFuel << "E" << "F";
    listTemp << "C" << "H";
    Vitesse = new Jonas_compteur;
    Vitesse->setValue(0);
    CompteTours = new Jonas_compteur(8000, listRpm, 70 , 210, 6000, "x1000rpm", 17, 0, 1, 100);
    CompteTours->setValue(0);
    Essence = new Jonas_compteur(100, listFuel, -35, 35, 100, "", 3, 0, 1, 80);
    Essence->setValue(0);
    Essence->setPos(170,-90);
    CompteTours->setPos(-190,0);
    jaugeTemperature = new Jonas_compteur(100, listTemp, -35, 35, 100, "", 3, 0, 1, 80);
    jaugeTemperature->setValue(0);
    jaugeTemperature->setPos(160, 65);
    VoyantBatterie = new jonas_voyant_simple(":/icons/icon-battery.jpg", 25, 25, 25);
    VoyantBatterie->setPos(15,75);
    croisement = new jonas_voyant_simple(":/icons/dipped-beam.jpg", 25, 25, 25);
    croisement->setPos(-20, 75);
    route = new jonas_voyant_simple(":/icons/main-beam.jpg", 25, 25, 25);
    route->setPos(-55, 75);
    position = new jonas_voyant_simple(":/icons/position-lamp.jpg", 25, 25, 25);
    position->setPos(-90, 75);
    Clignotant = new jonas_voyant_clignotant();
    warning = new jonas_voyant_warning();
    CompteurKm = new jonas_compteurKm();
    CompteurKm->setPos(-35,50);
    this->addItem(VoyantBatterie);
    this->addItem(croisement);
    this->addItem(route);
    this->addItem(position);
    this->addItem(jaugeTemperature);
    this->addItem(CompteurKm);
    this->addItem(Vitesse);
    this->addItem(CompteTours);
    this->addItem(Essence);
    this->addItem(Clignotant);
    this->addItem(warning);
}
