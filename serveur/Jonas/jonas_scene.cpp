#include "jonas_scene.h"
#include "jonas_compteur.h"
#include <QDebug>

Jonas_scene::Jonas_scene(scene_globale *parent) : scene_globale(parent)
{
    QStringList listFuel;
    QStringList listRpm;
    for (int i=0; i<=10; i++) {
        listRpm << QString::number(i);
    }
    this->setBackgroundBrush(Qt::black);
    listFuel << "E" << "F";
    Vitesse = new Jonas_compteur;
    Vitesse->setValue(0);
    CompteTours = new Jonas_compteur(10000, listRpm, 70 , 210, "x1000rpm", 21, 0, 1, 100);
    CompteTours->setValue(0);
    Essence = new Jonas_compteur(100, listFuel, -50 , 50 , "fuel", 3, 0, 1, 100);
    Essence->setValue(0);
    Essence->setPos(200,-80);
    CompteTours->setPos(-220,0);
    this->addItem(Vitesse);
    this->addItem(CompteTours);
    this->addItem(Essence);

    // objets pas encore implémentées (= null)
    jaugeTemperature = nullptr;
    Clignotant = nullptr;
    VoyantBatterie = nullptr;
    position = nullptr;
    croisement = nullptr;
    route = nullptr;
    warning = nullptr;
    CompteurKm = nullptr;
}
