#include "jonas_scene.h"
#include "jonas_compteur.h"
#include "jonas_voyant_simple.h"
#include "jonas_voyant_clignotant.h"
#include "jonas_voyant_warning.h"
#include "jonas_compteurkm.h"
#include <QDebug>

Jonas_scene::Jonas_scene(scene_globale *parent) : scene_globale(parent)
{
    /// Initialisation de l'arrière plan
    this->setBackgroundBrush(Qt::black); // dessine l'arrière plan
    this->setSceneRect(-300,-200,580,400); // permet de bien cadrer la scène

    /// Initialisation des jauges
    // Compteur de vitesse
    Vitesse = new Jonas_compteur;
    Vitesse->setValue(0);

    // Compteur tr/min
    QStringList listRpm;
    for (int i=0; i<=8; i++) {
        listRpm << QString::number(i);
    }
    CompteTours = new Jonas_compteur(8000, 70, 210, 6000, "x1000rpm", 17, 1, 0, 1, 100, listRpm);
    CompteTours->setValue(0);
    CompteTours->setPos(-190,0);

    // Jauge d'essence
    QStringList listFuel;
    listFuel << "E" << "F";
    Essence = new Jonas_compteur(100, 215, 145, 100, "", 3, 0, 0, 1, 80, listFuel, 0);
    Essence->setValue(100);
    Essence->setPos(240,-90);

    // Jauge de température moteur
    QStringList listTemp;
    listTemp << "C" << "H";
    jaugeTemperature = new Jonas_compteur(100, 215, 145, 75, "", 3, 0, 0, 1, 80, listTemp, 0);
    jaugeTemperature->setValue(0);
    jaugeTemperature->setPos(240, 65);

    // Ecran LCD qui affiche les km parcourus
    CompteurKm = new jonas_compteurKm();
    CompteurKm->setPos(-40,65);

    /// Initialisation des voyants
    RearAntifog = new jonas_voyant_simple(":/icons/icon-rear-fog-lamp.jpg", 21, 21, 21);
    RearAntifog->setPos(27, 85);
    croisement = new jonas_voyant_simple(":/icons/dipped-beam.jpg", 21, 21, 21);
    croisement->setPos(-8, 85);
    route = new jonas_voyant_simple(":/icons/main-beam.jpg", 21, 21, 21);
    route->setPos(-43, 85);
    position = new jonas_voyant_simple(":/icons/position-lamp.jpg", 21, 21, 21);
    position->setPos(-78, 85);
    Clignotant = new jonas_voyant_clignotant();
    warning = new jonas_voyant_warning();
    jonas_voyant_simple *engineTemp = new jonas_voyant_simple(":/icons/icon-temperature-white.png", 17, 17, 17);
    engineTemp->setPos(160, 38);
    engineTemp->setValue(1);
    jonas_voyant_simple *voyantEssence = new jonas_voyant_simple(":/icons/icon-fuel-white.jpg", 17, 17, 17);
    voyantEssence->setPos(160, -120);
    voyantEssence->setValue(1);
    VoyantBatterie = new jonas_voyant_simple(":/icons/icon-battery.jpg", 21, 21, 21);
    VoyantBatterie->setPos(20,-90);
    handbrake = new jonas_voyant_simple(":/Images/voyant-liquide-frein.gif", 32, 32, 32);
    handbrake->setPos(27, -68);
    ABS = new jonas_voyant_simple(":/Images/voyant-abs.gif", 32, 32, 32);
    ABS->setPos(27, -30);
    SeatBelt = new jonas_voyant_simple(":/icons/icon-seatbelt.png", 21, 21, 21);
    SeatBelt->setPos(27, 22);
    CheckEngine = new jonas_voyant_simple(":/Images/check_engine.jpg", 32, 32, 32);
    CheckEngine->setPos(-35, -128);
    AirbagOn = new jonas_voyant_simple(":/icons/icon-airbag.png", 21, 21, 21);
    AirbagOn->setPos(-65, -110);
    OilTemp = new jonas_voyant_simple(":/icons/icon-oil-red.png", 22, 22, 22);
    OilTemp->setPos(-97, -80);
    OpenDoorBackLeftPassenger = new jonas_voyant_simple(":/icons/icon-doors-open.png", 32, 32, 32);
    OpenDoorBackLeftPassenger->setPos(-125, -50);
    OpenDoorBackRightPassenger = new jonas_voyant_simple(":/icons/icon-doors-open.png", 32, 32, 32);
    OpenDoorBackRightPassenger->setPos(-125, -50);
    OpenDoorFrontPassenger = new jonas_voyant_simple(":/icons/icon-doors-open.png", 32, 32, 32);
    OpenDoorFrontPassenger->setPos(-125, -50);
    OpenDoorDriver = new jonas_voyant_simple(":/icons/icon-doors-open.png", 32, 32, 32);
    OpenDoorDriver->setPos(-125, -50);
    RearWindowHeating = new jonas_voyant_simple(":/icons/icon-rear-window-heating.png", 22, 22, 22);
    RearWindowHeating->setPos(-100, 10);

    /// Ajout des objets sur la scène
    this->addItem(engineTemp);
    this->addItem(voyantEssence);
    this->addItem(Essence);
    this->addItem(jaugeTemperature);
    this->addItem(CompteTours);
    this->addItem(Vitesse);
    this->addItem(CompteurKm);
    this->addItem(VoyantBatterie);
    this->addItem(croisement);
    this->addItem(route);
    this->addItem(position);
    this->addItem(Clignotant);
    this->addItem(warning);
    this->addItem(handbrake);
    this->addItem(ABS);
    this->addItem(RearAntifog);
    this->addItem(SeatBelt);
    this->addItem(CheckEngine);
    this->addItem(AirbagOn);
    this->addItem(OilTemp);
    this->addItem(OpenDoorBackLeftPassenger);
    this->addItem(RearWindowHeating);
}
