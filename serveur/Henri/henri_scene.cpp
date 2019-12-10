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

//    jaugeTemperature=new jaugeTemperatureHenri();
//    addItem(jaugeTemperature);

    stop=new stopHenri();
    jaugeTemperature=stop->jt;
    addItem(jaugeTemperature);
    addItem(stop);

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


    //les voyant dont je ne me suis pas encore occupé, je les met en onoff pour pas de pb
    AdaptiveSuspensionDampers=new onoff();
    addItem(AdaptiveSuspensionDampers);
    AutomaticTransmissionMode=new onoff();
    addItem(AutomaticTransmissionMode);
    FrontAntifog=new onoff();
    addItem(FrontAntifog);
    RearAntifog=new onoff();
    addItem(RearAntifog);
    SeatBelt =new onoff();
    addItem(SeatBelt);
    RearWindowHeating=new onoff();
    addItem(RearWindowHeating);
    CheckEngine=new onoff();
    addItem(CheckEngine);
    AdaptiveCruiseControl=new onoff();
    addItem(AdaptiveCruiseControl);
    AirbagOn=new onoff();
    addItem(AirbagOn);
    CruiseControlOn=new onoff();
    addItem(CruiseControlOn);
    OilTemp=new onoff();
    addItem(OilTemp);
    SpeedLimit=new onoff();
    addItem(SpeedLimit);
    oilLevel=new onoff();
    addItem(oilLevel);

    this->setBackgroundBrush(QBrush(QColor("black")));
}

void henri_scene::paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*)
{
}


QRectF henri_scene::boundingRect() const
{
    return QRect(-500,-400,1000,800);
}
