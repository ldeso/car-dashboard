#include "henri_scene.h"


henri_scene::henri_scene(scene_globale *parent):scene_globale(parent)
{

    float px=0.8;
    float py=0.8;
    QTransform scalingTransform(px, 0, 0, py, 0, 0);

    fond=new sceneDeFondHenri();
    addItem(fond);
    fond->setTransform(scalingTransform);

    Vitesse=new cadrantHenri();
    Vitesse->resetTransform();
    addItem(Vitesse);
    Vitesse->setTransform(scalingTransform);

    Essence=new jaugeEssenceHenri();
    addItem(Essence);
    Essence->setTransform(scalingTransform);

    CompteTours=new jaugeToursMinuteHenri();
    addItem(CompteTours);
    CompteTours->setTransform(scalingTransform);

//    jaugeTemperature=new jaugeTemperatureHenri();
//    addItem(jaugeTemperature);
//    jaugeTemperature->setTransform(scalingTransform);

    OilTemp=new jaugeTemperatureHenri;
    addItem(OilTemp);
    OilTemp->setTransform(scalingTransform);

    Clignotant=new jaugeClignotantHenri();
    addItem(Clignotant);
    Clignotant->setTransform(scalingTransform);

    CompteurKm=new afficheKmHenri();
    addItem(CompteurKm);
    CompteurKm->setTransform(scalingTransform);

    VoyantBatterie=new onoffpaintHenri(-170,10,55,50,QPixmap(":/new/prefix1/icones/iconeBatterie.png"));
    addItem(VoyantBatterie);
    VoyantBatterie->setTransform(scalingTransform);

    warning=new onoff();
    addItem(warning);

    route=new feuxHenri();
    addItem(route);

    portesHenri* portes=new portesHenri();
    addItem(portes);
    portes->moveBy(400*px,-100*py);
    OpenDoorDriver=portes->DG;
    OpenDoorFrontPassenger=portes->DD;
    OpenDoorBackLeftPassenger=portes->PG;
    OpenDoorBackRightPassenger=portes->PD;
    BootOpen=portes->C;
    portes->setTransform(scalingTransform);

    this->setBackgroundBrush(QBrush(QColor("black")));
}

void henri_scene::paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*)
{
}


QRectF henri_scene::boundingRect() const
{
    return QRect(-500,-300,1000,600);
}
