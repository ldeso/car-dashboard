#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mygraphicitem.h"
#include "speedometer_lea.h"
#include "tachometergauge_lea.h"
#include "fuelgauge_lea.h"
#include "voyant_lea.h"
#include "aiguille_lea.h"
#include "deux_voyants_lea.h"
#include "quatre_voyants_lea.h"
#include <QFontDatabase>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
QFontDatabase::addApplicationFont(":/Seven Segment.ttf");
    ui->graphicsView->setBackgroundBrush(QBrush(Qt::black));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Scene()
{
    ui->graphicsView->setScene(scene);

    speedometer_Lea *compteur = new speedometer_Lea;
    compteur->parametrage(400.0,200.0,160.0,225,-270,270,220);
    compteur->setValue(120);
    scene->addItem(compteur);

    deux_voyants_lea *fuel = new deux_voyants_lea;
    fuel->parametrage(580,320,":/fuel.png",":/fuel2.png");
    fuel->setSize(30,30);
    fuel->on=1;
    scene->addItem(fuel);

    FuelGauge_lea *GaugeEssence= new FuelGauge_lea;
    GaugeEssence->parametrage(650,250,25,100,625,350,625,250);
    GaugeEssence->setValue(25);
    scene->addItem(GaugeEssence);

    TachometerGauge_Lea *Gauge_Tours = new TachometerGauge_Lea;
    Gauge_Tours->parametrage(140.0,240.0,130.0,230,50,180,41,6);
    Gauge_Tours->setValue(5000);
    scene->addItem(Gauge_Tours);

    voyant_Lea *porteD_arr_ouverte = new voyant_Lea;
    porteD_arr_ouverte->parametrage(380,400,":/PorteOuvertePassagerD.png");
    porteD_arr_ouverte->setSize(80,80);
    porteD_arr_ouverte->on=1;
    scene->addItem(porteD_arr_ouverte);

    voyant_Lea *porteG_arr_ouverte = new voyant_Lea;
    porteG_arr_ouverte->parametrage(380,400,":/PorteOuvertePassagerG.png");
    porteG_arr_ouverte->setSize(80,80);
    porteG_arr_ouverte->on=0;
    scene->addItem(porteG_arr_ouverte);

    voyant_Lea *porteD_avt_ouverte = new voyant_Lea;
    porteD_avt_ouverte->parametrage(380,400,":/PorteOuverte.png");
    porteD_avt_ouverte->setSize(80,80);
    porteD_avt_ouverte->on=0;
    scene->addItem(porteD_avt_ouverte);

    voyant_Lea *porteG_avt_ouverte = new voyant_Lea;
    porteG_avt_ouverte->parametrage(380,400,":/PorteOuverteConducteur.png");
    porteG_avt_ouverte->setSize(80,80);
    porteG_avt_ouverte->on=0;
    scene->addItem(porteG_avt_ouverte);

    voyant_Lea *clignoGauche = new voyant_Lea;
    clignoGauche->parametrage(180,50,":/ClignottantGauche.png");
    clignoGauche->setSize(70,50);
    clignoGauche->on=1;
    scene->addItem(clignoGauche);

    voyant_Lea *clignoDroit = new voyant_Lea;
    clignoDroit->parametrage(580,50,":/ClignottantDroit.png");
    clignoDroit->setSize(70,50);
    clignoDroit->on=0;
    scene->addItem(clignoDroit);

    voyant_Lea *handbrakeOn = new voyant_Lea;
    handbrakeOn->parametrage(320,430,":/Handbrake.png");
    handbrakeOn->setSize(50,50);
    handbrakeOn->on=1;
    scene->addItem(handbrakeOn);

    voyant_Lea *Battery = new voyant_Lea;
    Battery->parametrage(260,430,":/Icones_Voyants/battery.gif");
    Battery->setSize(50,50);
    Battery->on=1;
    scene->addItem(Battery);

    voyant_Lea *Seatbelt = new voyant_Lea;
    Seatbelt->parametrage(215,440,":/Icones_Voyants/seatBeltSign_red.gif");
    Seatbelt->setSize(35,35);
    Seatbelt->on=5;
    scene->addItem(Seatbelt);

    voyant_Lea *Oil = new voyant_Lea;
    Oil->parametrage(160,430,":/Oil.png");
    Oil->setSize(50,50);
    Oil->on=1;
    scene->addItem(Oil);

    Quatre_Voyants_Lea *phares = new Quatre_Voyants_Lea;
    phares->parametrage(460,430,":/Icones_Voyants/dayLight.gif",":/Icones_Voyants/lowBeam.gif",":/Icones_Voyants/highBeam.gif");
    phares->setSize(50,50);
    phares->on=5;
    scene->addItem(phares);

    voyant_Lea *phares_brouillard_avant = new voyant_Lea;
    phares_brouillard_avant->parametrage(520,430,":/Icones_Voyants/frontFogLight.gif");
    phares_brouillard_avant->setSize(50,50);
    phares_brouillard_avant->on=1;
    scene->addItem(phares_brouillard_avant);

    voyant_Lea *phares_brouillard_arriere = new voyant_Lea;
    phares_brouillard_arriere->parametrage(570,430,":/Icones_Voyants/rearFogLight_blue.gif");
    phares_brouillard_arriere->setSize(50,50);
    phares_brouillard_arriere->on=1;
    scene->addItem(phares_brouillard_arriere);










}

