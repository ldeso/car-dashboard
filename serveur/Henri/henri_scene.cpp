#include "henri_scene.h"


henri_scene::henri_scene(scene_globale *parent):scene_globale(parent)
{
    fond=new sceneDeFondHenri();
    addItem(fond);

    Vitesse=new cadrantHenri();
    addItem(Vitesse);

    Essence=new jaugeEssenceHenri();
    addItem(Essence);

    CompteTours=new jaugeToursMinuteHenri();
    addItem(CompteTours);

    jaugeTemperature=new jaugeTemperatureHenri();
    addItem(jaugeTemperature);

    Clignotant=new jaugeClignotantHenri();
    addItem(Clignotant);

    CompteurKm=new afficheKmHenri();
    addItem(CompteurKm);

    VoyantBatterie=new jaugeBatterieHenri();
    addItem(VoyantBatterie);

    warning=new warninghenri();
    addItem(warning);

}

void henri_scene::paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*)
{
}


QRectF henri_scene::boundingRect() const
{
    return QRect(-700,-380,1400,780);
}
