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

    VoyantBatterie=new onoffpaintHenri(-170,10,55,50,QPixmap(":/new/prefix1/icones/iconeBatterie.png"));
    addItem(VoyantBatterie);

    warning=new onoff();
    addItem(warning);

    route=new onoffpaintHenri(-35,40,70,70,QPixmap(":/new/prefix1/icones/iconeRoute.png"));
    addItem(route);

    croisement=new onoffpaintHenri(-35,40,70,70,QPixmap(":/new/prefix1/icones/iconeCode.png"));
    addItem(croisement);

    position=new onoffpaintHenri(-35,40,70,70,QPixmap(":/new/prefix1/icones/iconeRoute.png"));
    addItem(position);

    portesHenri* portes=new portesHenri();
    addItem(portes);
    portes->moveBy(400,-100);
    OpenDoorDriver=portes->DG;
    OpenDoorFrontPassenger=portes->DD;
    OpenDoorBackLeftPassenger=portes->PG;
    OpenDoorBackRightPassenger=portes->PD;
    BootOpen=portes->Cof;
    BonnetOpen=portes->Cap;

    this->setBackgroundBrush(QBrush(QColor("black")));
}

void henri_scene::paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*)
{
}


QRectF henri_scene::boundingRect() const
{
    return QRect(-300,-300,600,600);
}
