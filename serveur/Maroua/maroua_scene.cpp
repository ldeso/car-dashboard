#include "maroua_scene.h"
#include "Henri/onoff.h"

#include <QGraphicsView>
#include<QDateTime>

maroua_scene::maroua_scene(scene_globale *parent) :
    scene_globale(parent)
{

//    cadrantessence *essence= new cadrantessence();
//    cadranttour *tour = new cadranttour();

    jaugeTemperature=new cadranthuile();
    Vitesse = new cadrantvitesse();
    CompteTours = new cadrantcontour();
    Essence=new cadrantessence();
    //cadranttempmoteur *temp=new cadranttempmoteur();
//    cadrantcontour *contour=new cadrantcontour();
    CompteurKm=new onoff();


//    addItem(contour);
//    addItem(essence);
//    addItem(tour);

    addItem(CompteTours);
    addItem(CompteurKm);
    addItem(Essence);
    addItem(jaugeTemperature);
    addItem(Vitesse);



}




