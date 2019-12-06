#include "kodjo_scene.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include "Kodjo/Cadran_Kodjo.h"
#include <QDebug>


kodjo_scene::kodjo_scene(scene_globale *parent):scene_globale(parent)
{
    //scene = new kodjo_scene;

    this->setBackgroundBrush(Qt::gray);
    Vitesse = new Cadran_Kodjo("V", "Km/h", -30,210,10,0);

    CompteTours = new Cadran_Kodjo("M", "tx1000/min", -30,210,10,1);

    Essence = new Cadran_Kodjo("E", "-", -30,210,10,1);

    //jaugeTemperature = new Cadran_Kodjo("H", "-", -30,210,10,1);

    OilTemp = new Cadran_Kodjo("H", "-", -30,210,10,1);

    this->addItem(Vitesse);
    Vitesse->setPos(0,0);

   // float vitesse = getValue();

    //qDebug() << "vitesse = " << vitesse;
    //float vitesse = Vitesse->getValueMax();

    this->addItem(CompteTours);
    CompteTours->setPos(500,0);

    this->addItem(Essence);
    Essence->setPos(-300,200);

    this->addItem(jaugeTemperature);
    jaugeTemperature->setPos(900,200);
    /*Vitesse->Choix_Type_Cadran("V");
    Vitesse->setPos(0,0);
    Vitesse->Affichage_Texte_Cadran_General("Km/h");
    Vitesse->Setteur_Graduation_Moteur_Vitesse(-30,210,10,0);*/
    //int vitesse = Vitesse->getValue();

    //qDebug() << "vitesse = " << vitesse;
    //qDebug() << "vitesse = " << Vitesse->getValue();

//    this->addItem(Rotation_Moteur);
//    Rotation_Moteur->Choix_Type_Cadran("M");
//    Rotation_Moteur->setPos(500,0);
//    Rotation_Moteur->Affichage_Texte_Cadran_General("t/min" );
//    Rotation_Moteur->Setteur_Graduation_Moteur_Vitesse(-30,210,10,1);

//    this->addItem(Niveau_Essence);
//    Niveau_Essence->Choix_Type_Cadran("E");
//    Niveau_Essence->Setteur_Graduation_Essence_Huile("E");
//    Niveau_Essence->setPos(-300, 200);

//    this->addItem(Niveau_Huile);
//    Niveau_Huile->Choix_Type_Cadran("H");
//    Niveau_Huile->Setteur_Graduation_Essence_Huile("H");
//    Niveau_Huile->setPos(900, 200);
}
