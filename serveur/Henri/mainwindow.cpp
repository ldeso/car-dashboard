#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new sceneGlobale();
    ui->graphicsView->setScene(scene);

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
    scene->vitesse->setValue(ui->sliderVitesse->value());
    scene->update();
}


void MainWindow::tou()
{
    scene->CompteTours->setValue(ui->sliderToursMinute->value());
    scene->update();
}

void MainWindow::ess()
{
    scene->Essence->setValue(ui->sliderEssence->value());
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
    scene->jaugeCligno->setValue(0);
    scene->update();
}

void MainWindow::cli()
{
    scene->update();
}

void MainWindow::sty(QString t)
{
    scene->vitesse->styleTexte=t;
    scene->update();
}

