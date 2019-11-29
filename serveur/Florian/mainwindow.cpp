#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new SceneFlorian();
    ui->scene->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}
