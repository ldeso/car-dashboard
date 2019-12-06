#include "maroua_scene.h"

#include <QGraphicsView>
#include<QDateTime>

maroua_scene::maroua_scene(scene_globale *parent) :
    scene_globale(parent)
{

    cadrantessence *essence= new cadrantessence();
    cadranttour *tour = new cadranttour();
    Vitesse = new cadrantvitesse();
    CompteTours = new cadranttour();
    //cadranttempmoteur *temp=new cadranttempmoteur();
    cadrantcontour *contour=new cadrantcontour();


    addItem(contour);
    addItem(Vitesse);
    addItem(essence);
    addItem(tour);



}




