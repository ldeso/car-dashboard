#include "maroua_scene.h"
#include "Henri/onoff.h"


maroua_scene::maroua_scene(scene_globale *parent) :
    scene_globale(parent)
{


    jaugeTemperature=new cadranttempmoteur();
    Vitesse = new cadrantvitesse();
    cadrantcontour *MainDial = new cadrantcontour();
    Essence=new cadrantessence();
    CompteTours=new cadranttour();
    Clignotant = new VoyantsMaroua();
    warning = new warningmaroua;
    AirbagOn=new autresvoyants("/home/sahli/Bureau/Icones/voyant-airbag.gif",-100,-360,50);
    SeatBelt= new autresvoyants("/home/sahli/Bureau/Icones/ceinture.jpg",50,-350,50);
    VoyantBatterie=new autresvoyants("/home/sahli/Bureau/Icones/voyant-batterie.gif",-310,-210,40);
    OpenDoorDriver=new autresvoyants("/home/sahli/Bureau/Icones/portieres.jpg",-20,-370,50);
    position = new autresvoyants("/home/sahli/Bureau/Icones/voyant_feux_position.jpg", 300,-160,40);
    croisement =new autresvoyants("/home/sahli/Bureau/Icones/voyant_feux_croisement.jpg",280,-190,40);
    route = new autresvoyants ("/home/sahli/Bureau/Icones/voyant_feux_route.jpg",320,-130,40);

    addItem(MainDial);
    addItem(CompteTours);
    addItem(Essence);
    addItem(jaugeTemperature);
    addItem(Vitesse);
    addItem(Clignotant);
    addItem(warning);
    addItem(AirbagOn);
    addItem(SeatBelt);
    addItem(VoyantBatterie);
    addItem(OpenDoorDriver);
    addItem(position);
    addItem(croisement);
    addItem(route);

}




