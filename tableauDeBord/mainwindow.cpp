#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    fond = new sceneDeFondHenri();
    scene->addItem(fond);

    cadrant=new cadrantHenri();
    scene->addItem(cadrant);

    jaugeEssence=new jaugeEssenceHenri();
    scene->addItem(jaugeEssence);

    jaugeToursMin=new jaugeToursMinuteHenri();
    scene->addItem(jaugeToursMin);

    connect(ui->sliderVitesse,SIGNAL(actionTriggered(int)),this,SLOT(vit()));
    connect(ui->sliderToursMinute,SIGNAL(actionTriggered(int)),this,SLOT(tou()));
    connect(ui->fontComboBox,SIGNAL(activated(QString)),this,SLOT(sty(QString)));
    connect(ui->sliderEssence,SIGNAL(actionTriggered(int)),this,SLOT(ess()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::vit()
{
    cadrant->vitesse=ui->sliderVitesse->value();
    scene->update();
}


void MainWindow::tou()
{
    jaugeToursMin->valeur=ui->sliderToursMinute->value();
    scene->update();
}

//void MainWindow::sty(QString s)
//{
//    cadrant->styleTexte=s;
//    scene->update();
//}

void MainWindow::ess()
{
    jaugeEssence->valeur=ui->sliderEssence->value();
    scene->update();
}
