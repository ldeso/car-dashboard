#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    server = new QTcpServer(this);
    server->listen(QHostAddress::Any, 2222);
    connect(server,SIGNAL(newConnection()),this, SLOT(connexion()));
    //connect(ui->lineEdit,SIGNAL(returnPressed()),this, SLOT(display()));
    c = new Compteur(50,50,200,200, 200);
    QGraphicsScene * scene = new QGraphicsScene(this);
    scene->addItem(c);
    ui->graphicsView->setScene(scene);
    //ui->graphicsView->setBackgroundBrush(QBrush(QColor(Qt::black)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connexion()
{
    socket = this->server->nextPendingConnection();
    qDebug() << "connexion etabli";
    //socket->write("ok\n");
    /*while(socket->state() != 0 ){
        if(!socket->waitForReadyRead())
            qDebug() << "temps d attente depasse";
        else

    }*/
    connect(socket, SIGNAL(readyRead()),this, SLOT(reception()));
}

void MainWindow::display()
{

    /*QByteArray qba = ui->lineEdit->text().toUtf8();
    socket->write(qba);*/

}

void MainWindow::reception()
{
    //ui->text->setText(QString(socket->readAll()));
    QString string(socket->readAll());
    QString message = string.section(' ',0,2);
    if(message=="BUS CANN SPEED"){
        int vitesse = string.section(' ', 3,3).toInt();
        if(vitesse>=0 && vitesse <= c->getSpeedMax()){
            c->setSpeed(vitesse);
            ui->graphicsView->scene()->update();
        }
    }
    else
        qDebug() << "erreur lors de la reception du message";

}


