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
    this->setBackgroundBrush(Qt::black); // dessine l'arrière plan
    this->setSceneRect(-300,-200,580,400); // permet de bien cadrer la scène
    listFuel << "E" << "F";
    listTemp << "C" << "H";
    Vitesse = new Jonas_compteur;
    Vitesse->setValue(0);
    CompteTours = new Jonas_compteur(8000, 70, 210, 6000, "x1000rpm", 17, 1, 0, 1, 100, listRpm);
    CompteTours->setValue(0);
    Essence = new Jonas_compteur(100, 215, 145, 100, "", 3, 0, 0, 1, 80, listFuel, 0);
    Essence->setValue(100);
    Essence->setPos(240,-90);
    CompteTours->setPos(-190,0);
    jaugeTemperature = new Jonas_compteur(100, 215, 145, 100, "", 3, 0, 0, 1, 80, listTemp, 0);
    jaugeTemperature->setValue(0);
    jaugeTemperature->setPos(240, 65);
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
    this->addItem(CompteTours);
    this->addItem(Vitesse);
    this->addItem(CompteurKm);
    this->addItem(Essence);
    this->addItem(Clignotant);
    this->addItem(warning);
}
