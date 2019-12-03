#include "henri_scene.h"


henri_scene::henri_scene(scene_globale *parent):scene_globale(parent)
{
    fond=new sceneDeFondHenri();
    addItem(fond);

    Vitesse=new cadrantHenri();
    Vitesse->resetTransform();
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

    route=new feuxHenri();
    addItem(route);

    portesHenri* portes=new portesHenri();
    addItem(portes);
    portes->moveBy(400,-100);
    OpenDoorDriver=portes->DG;
    OpenDoorFrontPassenger=portes->DD;
    OpenDoorBackLeftPassenger=portes->PG;
    OpenDoorBackRightPassenger=portes->PD;
    BootOpen=portes->C;

    this->setBackgroundBrush(QBrush(QColor("black")));
}

void henri_scene::paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*)
{
}


QRectF henri_scene::boundingRect() const
{
    return QRect(-700,-350,1400,700);
}
