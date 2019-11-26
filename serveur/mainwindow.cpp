#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include "Hugo/hugo_scene.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    server = new QTcpServer(this);
    server->listen(QHostAddress::Any, 2222);
    connect(server,SIGNAL(newConnection()),this, SLOT(connexion()));
    //connect(ui->lineEdit,SIGNAL(returnPressed()),this, SLOT(display()));

    dashboard=new hugo_scene;

    ui->graphicsView->setScene(dashboard);
    //ui->graphicsView->setBackgroundBrush(QBrush(QColor(Qt::black)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


/**
 * @brief MainWindow::connexion
 * @details etabli la connexion avec le client
 */
void MainWindow::connexion()
{
    socket = this->server->nextPendingConnection();
    qDebug() << "connexion etabli";
    connect(socket, SIGNAL(readyRead()),this, SLOT(reception()));
}

/**
 * @brief MainWindow::reception
 * @details gere la reception des messages.
 * todoux : ajouter les conditions pour les differents messages recu
 */
void MainWindow::reception()
{
    //ui->text->setText(QString(socket->readAll()));
    QString string(socket->readAll());
    QString message = string.section(' ',0,1);
    if(message=="CANN SPEED"){
        int vitesse = string.section(' ', 2,2).toInt();
        if(vitesse>=0 && vitesse <= dashboard->vitesse->getValueMax()){
            dashboard->vitesse->setValue(vitesse);
            ui->graphicsView->scene()->update();
            QString text = "OK";
            socket->write(text.toUtf8());
        }
        else{
            QString text;
            text = QString("vitesse incorrect, vitesse comprise entre 0 et %1").arg(dashboard->vitesse->getValueMax());
            socket->write(text.toUtf8());
        }
    }
    if(message=="CANN RPM"){
        int rpm = string.section(' ', 2,2).toInt();
        if(rpm>=0 && rpm <= dashboard->rpm->getValueMax()){
            dashboard->rpm->setValue(rpm);
            ui->graphicsView->scene()->update();
            QString text = "OK";
            socket->write(text.toUtf8());
        }
        else{
            QString text;
            text = QString("vitesse incorrect, vitesse comprise entre 0 et %1").arg(dashboard->rpm->getValueMax());
            socket->write(text.toUtf8());
        }
    }
    else
        qDebug() << "erreur lors de la reception du message";

}


