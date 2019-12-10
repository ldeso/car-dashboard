#include "youcef_scene.h"
#include <QFontDatabase>


Youcef_Scene::Youcef_Scene(scene_globale* parent)
    : scene_globale(parent)
{
    CarDialerPrototype *MainDial = new CarDialerPrototype();
    addItem(MainDial);

    MainDisplay_Youcef *Ecran = new MainDisplay_Youcef();
    addItem(Ecran);

    QFontDatabase::addApplicationFont(":/new/font/Seven_Segment.ttf");

    CompteTours = new Tachometer();
    addItem(CompteTours);

    Vitesse = new CarSpeedDial();
    addItem(Vitesse);


    Essence= new FuelGauge();
    addItem(Essence);

    jaugeTemperature= new EngineHeatGauge();
    addItem(jaugeTemperature);


    Clignotant = new FlashingLight_Youss();
    addItem(Clignotant);

    warning = new Warning_Youss();
    addItem(warning);

    /*light Indicators*/

    position =new Indicator_Youss(235,-50,":/new/logos/Icones/highBeam.gif",50,50,Qt::green);
    //    position->setValue(1);
    addItem(position);

    route =new Indicator_Youss(285,-50,":/new/logos/Icones/dayLight.gif",50,50,Qt::green);
    //    route ->setValue(1);
    addItem(route);

    croisement =new Indicator_Youss(330,-50,":/new/logos/Icones/lowBeam.gif",50,50,Qt::green);
    //    croisement->setValue(1);
    addItem(croisement);

    RearAntifog = new Indicator_Youss (350,-90,":/new/logos/Icones/rearFogLight_blue.gif",50,50,Qt::blue);
    //    RearAntifog->setValue(1);
    addItem(RearAntifog);


    FrontAntifog = new Indicator_Youss (360,-130,":/new/logos/Icones/frontFogLight.gif",50,50,Qt::yellow);
    //    FrontAntifog->setValue(1);
    addItem(FrontAntifog);




    /* Door indicators*/

    OpenDoorBackRightPassenger = new Indicator_Youss (-280,-60,":/new/logos/Icones/backrightDoorOpen.gif",40,40,Qt::transparent);
    //    OpenDoorBackRightPassenger->setValue(1);
    addItem(OpenDoorBackRightPassenger);

    OpenDoorBackLeftPassenger = new Indicator_Youss (-330,-60,":/new/logos/Icones/backLeftDoorOpen.gif",40,40,Qt::transparent);
    //    OpenDoorBackLeftPassenger->setValue(1);
    addItem(OpenDoorBackLeftPassenger);


    BootOpen = new Indicator_Youss (-390,-115,":/new/logos//Icones/bootOpen_red.gif",60,60,Qt::transparent);
    //    BootOpen->setValue(1);
    addItem(BootOpen);

    BonnetOpen = new Indicator_Youss (-260,-115,":/new/logos/Icones/bonnetOpen_red.gif",60,60,Qt::transparent);
    //    BonnetOpen->setValue(1);
    addItem(BonnetOpen);

    /* important indicators*/

    handbrake = new Indicator_Youss(210,-90,":/new/logos/Icones/brake_warning.gif",50,50,Qt::red);
    //    handbrake->setValue(1);
    addItem(handbrake);

    VoyantBatterie = new Indicator_Youss(200,-130,":/new/logos/Icones/battery.gif",40,40,Qt::red);
    //    VoyantBatterie->setValue(1);
    addItem(VoyantBatterie);

    SeatBelt = new Indicator_Youss (220,-180,":/new/logos/Icones/seatBeltSign_red.gif",40,40,Qt::red);
    //    SeatBelt->setValue(1);
    addItem(SeatBelt);


    /*technic indicators*/

    CheckEngine = new Indicator_Youss (260,-200,":/new/logos/Icones/checkEngine.gif",40,40,Qt::red);
    //    CheckEngine->setValue(1);
    addItem(CheckEngine);

    ABS = new Indicator_Youss (-260,-150,":/new/logos/Icones/ABS3.png",40,40,"#f87626");
    //    ABS->setValue(1);
    addItem(ABS);

    AdaptiveSuspensionDampers=new Indicator_Youss (-350,-180,":/new/logos/Icones/AdaptiveSuspensionDampers_yellow.gif",50,50,Qt::yellow);
    //    AdaptiveSuspensionDampers->setValue(1);
    addItem(AdaptiveSuspensionDampers);

    OilTemp = new Indicator_Youss(-370,-130,":/new/logos/Icones/icon-oil-red.png",40,20,Qt::red);
    //    OilTemp->setValue(1);
    addItem(OilTemp);


    /*other indicators*/

    CruiseControlOn = new Indicator_Youss (310,-200,":/new/logos/Icones/Cruise_Control2.gif",40,40,Qt::green);
    //    CruiseControlOn->setValue(1);
    addItem(CruiseControlOn);

    RearWindowHeating = new Indicator_Youss (350,-180,":/new/logos/Icones/rearWindowHeating_yellow.gif",40,40,(Qt::yellow));
    //    RearWindowHeating->setValue(1);
    addItem(RearWindowHeating);

    AirbagOn= new Indicator_Youss (-300,-190,":/new/logos/Icones/airBag.gif",50,50,Qt::red);
    //    AirbagOn->setValue(1);
    addItem(AirbagOn);




}
