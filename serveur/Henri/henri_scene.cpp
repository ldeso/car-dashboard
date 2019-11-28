#include "henri_scene.h"


henri_scene::henri_scene(scene_globale *parent):scene_globale(parent)
{
    fond=new sceneDeFondHenri();
    addItem(fond);

    vitesse=new cadrantHenri();
    addItem(vitesse);

    Essence=new jaugeEssenceHenri();
    addItem(Essence);

    CompteTours=new jaugeToursMinuteHenri();
    addItem(CompteTours);

    jaugeTemperature=new jaugeTemperatureHenri();
    addItem(jaugeTemperature);

    Clignotant=new jaugeClignotant();
    addItem(Clignotant);
}

void henri_scene::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
}


QRectF henri_scene::boundingRect() const
{
    return QRect(-800,-450,1600,900);
}
