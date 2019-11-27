#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new sceneGlobale();
    ui->graphicsView->setScene(scene);

    scene->fond = new sceneDeFondHenri();
    scene->addItem(scene->fond);

    scene->fond = new sceneDeFondHenri();
    scene->addItem(scene->fond);

    scene->cadrant=new cadrantHenri();
    scene->addItem(scene->cadrant);

    scene->jaugeEssence=new jaugeEssenceHenri();
    scene->addItem(scene->jaugeEssence);

    scene->jaugeToursMin=new jaugeToursMinuteHenri();
    scene->addItem(scene->jaugeToursMin);

    scene->jaugeTemperature=new jaugeTemperatureHenri();
    scene->addItem(scene->jaugeTemperature);

    scene->jaugeCligno=new jaugeClignotant();
    scene->addItem(scene->jaugeCligno);


    connect(ui->sliderVitesse,SIGNAL(actionTriggered(int)),this,SLOT(vit()));
    connect(ui->sliderToursMinute,SIGNAL(actionTriggered(int)),this,SLOT(tou()));
    connect(ui->sliderEssence,SIGNAL(actionTriggered(int)),this,SLOT(ess()));
//    connect(ui->fontComboBox,SIGNAL(activated(QString)),this,SLOT(sty(QString)));
    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(cli_g()));
    connect(ui->pushButton_2,SIGNAL(clicked(bool)),this,SLOT(cli_d()));
    connect(ui->pushButton_3,SIGNAL(clicked(bool)),this,SLOT(cli_s()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::vit()
{
    scene->cadrant->setValue(ui->sliderVitesse->value());
    scene->update();
}


void MainWindow::tou()
{
    scene->jaugeToursMin->setValeur(ui->sliderToursMinute->value());
    scene->update();
}

void MainWindow::ess()
{
    scene->jaugeEssence->setValeur(ui->sliderEssence->value());
    scene->update();
}

void MainWindow::cli_g()
{
    scene->jaugeCligno->cligno=-1;
    cli();
}

void MainWindow::cli_d()
{
    scene->jaugeCligno->cligno=1;
    cli();
}

void MainWindow::cli_s()
{
    scene->jaugeCligno->cligno=0;
    scene->jaugeCligno->setValeur(0);
    scene->update();
}

void MainWindow::cli()
{
    scene->jaugeCligno->setValeur(scene->jaugeCligno->getValeur()+1);
    if (scene->jaugeCligno->getValeur()>8)
        scene->jaugeCligno->setValeur(0);
    scene->update();
    QTest::qWait(60);
    if (scene->jaugeCligno->cligno != 0)
        cli();

}

void MainWindow::sty(QString t)
{
    scene->cadrant->styleTexte=t;
    scene->update();
}

