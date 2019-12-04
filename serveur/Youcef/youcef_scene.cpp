#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);


    ui->graphicsView->setScene(scene);
    ui->SpeedSlider->setValue(0);


scene->addItem(MainDial);
scene->addItem(Speed);
scene->addItem(tacho);
scene->addItem(fuel);
scene->addItem(heat);

connect(ui->SpeedSlider,SIGNAL(actionTriggered(int)),this,SLOT(Speedometer()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Speedometer()
{
   Speed->speedvalue = ui->SpeedSlider->value();

     scene->update();
}
void MainWindow::mascene()
{ ui->graphicsView->setScene(scene);
    Speed->speedvalue = ui->SpeedSlider->value();
    scene->addItem(Speed);

}
