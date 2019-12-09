#include "kodjo_scene.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include "Kodjo/Cadran_Kodjo.h"
#include <QDebug>

///Dans ce projet, nous avons avons utilisé qu'une seule classe Cadran_Kodjo.
/// Chaque objet est initialisé par le constructeur.
/// "V" = Vitesse, "M" = Tour moteur, "E" = Essence, "B" = Batterie, "P" = Porte ouverte, "C" = Ceinture de sécurité

kodjo_scene::kodjo_scene(scene_globale *parent):scene_globale(parent)
{

    this->setBackgroundBrush(Qt::gray);
    Vitesse = new Cadran_Kodjo("V", "Km/h", -30,210,10,0);

    CompteTours = new Cadran_Kodjo("M", "tx1000/min", -30,210,10,1);

    Essence = new Cadran_Kodjo("E", "-", -30,210,10,1);

    //jaugeTemperature = new Cadran_Kodjo("H", "-", -30,210,10,1);

    OilTemp = new Cadran_Kodjo("H", "-", -30,210,10,1);

    VoyantBatterie = new Cadran_Kodjo("B", "-", -30,210,10,1);

    OpenDoorDriver = new Cadran_Kodjo("P", "-", -30,210,10,1);

    SeatBelt = new Cadran_Kodjo("C", "-", -30,210,10,1);

    this->addItem(Vitesse);
    Vitesse->setPos(0,0);

    this->addItem(CompteTours);
    CompteTours->setPos(500,0);

    this->addItem(Essence);
    Essence->setPos(-300,200);

    this->addItem(OilTemp);
    OilTemp->setPos(900,200);

    this->addItem(VoyantBatterie);
    VoyantBatterie->setPos(-300, 200);

    this->addItem(OpenDoorDriver);
    OpenDoorDriver->setPos(-275, 200);

    this->addItem(SeatBelt);
    SeatBelt->setPos(-200, 200);

    //this->addItem(jaugeTemperature);
    //jaugeTemperature->setPos(900,200);

}
