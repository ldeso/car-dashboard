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
    scene->cadrant->valeur=ui->sliderVitesse->value();
    scene->update();
}


void MainWindow::tou()
{
    scene->jaugeToursMin->valeur=ui->sliderToursMinute->value();
    scene->update();
}

void MainWindow::ess()
{
    scene->jaugeEssence->valeur=ui->sliderEssence->value();
    scene->update();
}
