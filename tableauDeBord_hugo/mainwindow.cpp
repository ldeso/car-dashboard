#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mygraphicsitem.h"
#include "compteur.h"
#include <QGraphicsView>
#include <QList>
#include "aiguille.h"
#include "verre.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    test=new MyGraphicsitem();
    scene->addItem(test);

    Compteur *vitesse=new Compteur;
    QStringList graduations_vitesse;
    graduations_vitesse<<"0"<<"20"<<"40"<<"60"<<"80"<<"100"<<"120"<<"140"<<"160"<<"180"<<"200"<<"220";
    vitesse->Parametrage(0,0,90,210,-30,graduations_vitesse,0,64,128);
    scene->addItem(vitesse);

    aiguille_vitesse=new Aiguille;
    aiguille_vitesse->parametrage(0,0,90);
    aiguille_vitesse->angle=150;
    scene->addItem(aiguille_vitesse);

    verre * verre_vitesse=new verre;
    verre_vitesse->parametrage(0,0,100);
    scene->addItem(verre_vitesse);

    Compteur *rpm=new Compteur;
    QStringList graduations_rpm;
    graduations_rpm<<"0"<<"1"<<"2"<<"3"<<"4"<<"5"<<"6"<<"7"<<"8";
    rpm->Parametrage(-170,20,80,210,60,graduations_rpm,0,64,128,5,120,0,0);
    scene->addItem(rpm);

    aiguille_rpm=new Aiguille;
    aiguille_rpm->parametrage(-170,20,80);
    aiguille_rpm->angle=150;
    scene->addItem(aiguille_rpm);

    Compteur *essence=new Compteur;
    QStringList graduations_essence;
    graduations_essence<<"E"<<"F";
    essence->Parametrage(140,-60,40,-45,45,graduations_essence,0,64,128);
    scene->addItem(essence);

    aiguille_essence=new Aiguille;
    aiguille_essence->parametrage(140,-60,40);
    aiguille_essence->angle=-45;
    scene->addItem(aiguille_essence);

    Compteur *temperature=new Compteur;
    QStringList graduations_temperature;
    graduations_temperature<<"C"<<"H";
    temperature->Parametrage(160,30,40,-45,45,graduations_temperature,0,64,128);
    scene->addItem(temperature);

    aiguille_temperature=new Aiguille;
    aiguille_temperature->parametrage(160,30,40);
    aiguille_temperature->angle=-45;
    scene->addItem(aiguille_temperature);


    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(START()));
    connect(ui->pushButton_2,SIGNAL(clicked(bool)),this,SLOT(NEXT()));
    connect(ui->pushButton_3,SIGNAL(clicked(bool)),this,SLOT(PREVIOUS()));
    connect(ui->pushButton_4,SIGNAL(clicked(bool)),this,SLOT(Vmute()));
    connect(ui->pushButton_5,SIGNAL(clicked(bool)),this,SLOT(Vplus()));
    connect(ui->pushButton_2,SIGNAL(clicked(bool)),this,SLOT(Vmoins()));
    connect(ui->horizontalSlider,SIGNAL(actionTriggered(int)),this,SLOT(vit()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::vit()
{
    aiguille_vitesse->angle=ui->horizontalSlider->value();
    scene->update();
}

void MainWindow::START()
{

    if (radio_on==0){
        Current_Station=radio->START();
        radio_on=1;
    }
    else{
        radio->stop();
        radio_on=0;
    }
}

void MainWindow::NEXT()
{
    if (radio_on==1){
        Current_Station=radio->NEXT();
    }
}

void MainWindow::PREVIOUS()
{
    if (radio_on==1){
        Current_Station=radio->PREVIOUS();
        radio_on=1;
    }
}

void MainWindow::Vplus()
{
    volume+=10;
    radio->setVolume(volume);
}

void MainWindow::Vmoins()
{
    volume-=10;
    radio->setVolume(volume);
}

void MainWindow::Vmute()
{
    if (radio->isMuted()==false){
        radio->setMuted(true);
    }
    else{
        radio->setMuted(false);
    }
}
