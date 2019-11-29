#include "jonas_scene.h"
#include "jonas_compteur.h"
#include <QDebug>

Jonas_scene::Jonas_scene(scene_globale *parent) : scene_globale(parent)
{
    QStringList listFuel;
    QStringList listRpm;
    for (int i=0; i<=10; i+=1) {
        listRpm << QString::number(i);
    }
    this->setBackgroundBrush(Qt::black);
    listFuel << "F" << "E";
    Vitesse = new Jonas_compteur;
    Vitesse->setValue(0);
    CompteTours = new Jonas_compteur(10, listRpm, 70 , 210, "x1000rpm", 20, 0, 1, 100);
    CompteTours->setValue(0);
    Essence = new Jonas_compteur(5, listFuel, -50 , 50, "fuel", 4, 0, 1, 100);
    Essence->setValue(0);
    Essence->setPos(250,-80);
    CompteTours->setPos(-300,0);
    this->addItem(Vitesse);
    this->addItem(CompteTours);
    this->addItem(Essence);
    qDebug() << Vitesse->getValueMax();
}
