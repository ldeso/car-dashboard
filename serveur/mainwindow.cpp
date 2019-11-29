#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QTimer>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    server = new QTcpServer(this);
    server->listen(QHostAddress::Any, 2222);
    connect(server,SIGNAL(newConnection()),this, SLOT(connexion()));


   ///La scène par défault est
    dashboard=new hugo_scene();

    dashboard->Vitesse->getValue();

    QTimer *kmTimer=new QTimer;
    connect(kmTimer, SIGNAL(timeout()), this, SLOT(update_km()));
    kmTimer->setInterval(1000);
    kmTimer->start();

    ui->graphicsView->setScene(dashboard);

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
    qDebug() << string;
    if(message=="CANN SPEED"){
        int vitesse = string.section(' ', 2,2).toInt();
        if(vitesse>=0 && vitesse <= dashboard->Vitesse->getValueMax()){
            dashboard->Vitesse->setValue(vitesse);
            ui->graphicsView->scene()->update();
            QString text = "OK";
            socket->write(text.toLocal8Bit());
            vitesse_actuelle=vitesse;
        }
        else{
            QString text;
            text = QString("vitesse incorrect, vitesse comprise entre 0 et %1").arg(dashboard->Vitesse->getValueMax());
            socket->write(text.toLocal8Bit());
        }
    }
    else if(message=="CANN RPM"){
        int rpm = string.section(' ', 2,2).toInt();
        if(rpm>=0 && rpm <= dashboard->CompteTours->getValueMax()){
            dashboard->CompteTours->setValue(rpm);
            ui->graphicsView->scene()->update();
            QString text = "OK";
            socket->write(text.toLocal8Bit());
        }
        else{
            QString text;
            text = QString("rpm incorrect, rpm compris entre 0 et %1").arg(dashboard->CompteTours->getValueMax());
            socket->write(text.toUtf8());
        }
    }
    else if(message=="CANN BATTERY_LIGHT"){
        int battery_on = string.section(' ', 2,2).toInt();
        if(battery_on==0 || battery_on==1){
            dashboard->VoyantBatterie->setValue(battery_on);
            ui->graphicsView->scene()->update();
            QString text = "OK";
            socket->write(text.toLocal8Bit());
        }
        else{
            QString text;
            text = QString("valeur incorrecte, doit être égale à 0 ou 1");
            socket->write(text.toLocal8Bit());
        }
    }
    else if(message=="CANN GAZ"){
        int essence = string.section(' ', 2,2).toInt();
        if(essence>=0 && essence <= dashboard->Essence->getValueMax()){
            dashboard->Essence->setValue(essence);
            ui->graphicsView->scene()->update();
            QString text = "OK";
            socket->write(text.toLocal8Bit());
        }
        else{
            QString text;
            qDebug()<<text;
            text = QString("Quantité incorrect, quantité comprise entre 0 et %1").arg(dashboard->Essence->getValueMax());
            socket->write(text.toLocal8Bit());
        }
    }
    else if(message=="CANN TURN"){
        int cligno = string.section(' ', 2,2).toInt();
        if(cligno>=-1 && cligno <= 1){
            dashboard->Clignotant->setValue(cligno);
           // ui->graphicsView->scene()->update();
            QString text = "OK";
            socket->write(text.toLocal8Bit());
        }
        else{
            QString text;

            text = QString("Incorrect -1=>gauche 0=>null 1=>droite");
            socket->write(text.toLocal8Bit());
        }
    }
    if(message=="CANN DASHBOARD"){
        QStringList PRENOMS;
        PRENOMS<<"HUGO"<<"HENRI" << "JONAS";
        QString prenom = string.section(' ', 2,2);
        if (PRENOMS.contains(prenom)==true){
            if (prenom=="HUGO"){
                delete dashboard;
                dashboard =new hugo_scene;
                ui->graphicsView->setScene(dashboard);
            }
            if (prenom=="HENRI"){
                delete dashboard;
                dashboard =new henri_scene;
                ui->graphicsView->setScene(dashboard);
            }
            if (prenom=="JONAS"){
                delete dashboard;
                dashboard =new Jonas_scene;
                ui->graphicsView->setScene(dashboard);
            }
            ui->graphicsView->scene()->update();
            QString text = "OK";
            socket->write(text.toUtf8());
        }
        else{
            QString text;
            text = QString("Cette scène n'existe pas.");
            socket->write(text.toUtf8());
        }
    }
    else if(message=="CANN LIGHT"){
        int light = string.section(' ', 2,2).toInt();

        if(light>=0 && light <= 3){
            switch (light) {
            case 1:
                dashboard->position->setValue(1);
                dashboard->croisement->setValue(0);
                dashboard->route->setValue(0);
                break;
            case 2:
                dashboard->position->setValue(0);
                dashboard->croisement->setValue(1);
                dashboard->route->setValue(0);

                break;
            case 3:
                dashboard->position->setValue(0);
                dashboard->croisement->setValue(0);
                dashboard->route->setValue(1);

                break;
             default:
                dashboard->position->setValue(0);
                dashboard->croisement->setValue(0);
                dashboard->route->setValue(0);
                break;

            }
            ui->graphicsView->scene()->update();
            QString text = "OK";
            socket->write(text.toUtf8());
        }
        else{
            QString text;
            text = QString("valeur incorrect, valeur entre 0 et 3").arg(dashboard->Essence->getValueMax());
            socket->write(text.toUtf8());
        }
    }
    else if(message=="CANN WARNING"){
        int warning = string.section(' ', 2,2).toInt();
        if(warning>=0 && warning <= 1){
            dashboard->warning->setValue(warning);
            dashboard->Clignotant->setValue(2*warning);
            ui->graphicsView->scene()->update();
            QString text = "OK";
            socket->write(text.toUtf8());
        }
        else{
            QString text;
            text = QString("Quantité incorrect, vitesse comprise entre 0 et %1").arg(dashboard->Essence->getValueMax());
            socket->write(text.toUtf8());
        }
    }
    else
        qDebug() << "erreur lors de la reception du message";

}


void MainWindow::update_km()
{
    km_parcourus+=1.0*(vitesse_actuelle)/3600;
    dashboard->CompteurKm->setValue(km_parcourus);
    ui->graphicsView->scene()->update();
}




