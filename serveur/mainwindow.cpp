#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QTimer>
#include <QCoreApplication>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    server = new QTcpServer(this);
    server->listen(QHostAddress::Any, 2222);
    connect(server,SIGNAL(newConnection()),this, SLOT(connexion()));


    ///La scène par défault est
    dashboard=new Lea_scene();
    //    this->resize(dashboard->width()+31,dashboard->height()+63);//pour metre la fentre a la taille du dasboard, attention donc au taille
    //                                                               //la taille de la scene est le plus grand des ::boundingRect() des objets
    //    this->move(0,0);


    ui->graphicsView->setScene(dashboard);
    QResizeEvent* resizeEvent = new QResizeEvent(ui->graphicsView->size(), this->size());
    QCoreApplication::postEvent(this, resizeEvent);

    QTimer *kmTimer=new QTimer;
    connect(kmTimer, SIGNAL(timeout()), this, SLOT(update_km()));
    kmTimer->setInterval(500);
    kmTimer->start();

    ui->graphicsView->setScene(dashboard);

}

///
/// \brief MainWindow::acceleration Simulation d'une accélération
/// \details Fonction simulant une accélération linéaire avec changements de rapports de vitesse
/// \param time Durée de la simulation
///
void MainWindow::acceleration(int time)
{
    qDebug()<<"ok";
    float t=0;
    float vitesse=dashboard->Vitesse->getValue();
    int rapport=1;
    while (t<time){
        vitesse_actuelle=vitesse;
        if ((vitesse)<=dashboard->Vitesse->getValueMax()){
            dashboard->Vitesse->setValue(vitesse);
            if (vitesse<55){
                rapport=1;
                dashboard->CompteTours->setValue(vitesse*4500/55);
            }
            else if(vitesse<75){
                rapport=2;
                dashboard->CompteTours->setValue(vitesse*4500/75);
            }
            else if(vitesse<115){
                rapport=3;
                dashboard->CompteTours->setValue(vitesse*4500/115);
            }
            else if(vitesse<140){
                rapport=4;
                dashboard->CompteTours->setValue(vitesse*4500/140);
            }
            else{
                rapport=5;
                dashboard->CompteTours->setValue(vitesse*4500/185);
            }
        }
        ui->graphicsView->scene()->update();
        vitesse+=0.8;
        t+=0.1;
        QTest::qWait(100);

    }
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
            ui->graphicsView->scene()->update();
            QString text = "OK";
            socket->write(text.toLocal8Bit());
        }
        else{
            QString text;

            text = QString("Incorrect -1=>gauche 0=>null 1=>droite");
            socket->write(text.toLocal8Bit());
        }
    }
    else if(message=="CANN DASHBOARD"){
        QStringList PRENOMS;
        PRENOMS << "HUGO" << "HENRI" << "JONAS" << "LEA" << "LEO" << "FLORIAN"<<"KARIM"<<"LOTO";
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
            if (prenom=="LEA"){
                delete dashboard;
                dashboard =new Lea_scene;
                ui->graphicsView->setScene(dashboard);
            }
            if (prenom=="LEO"){
                delete dashboard;
                dashboard = new Leo_scene;
                ui->graphicsView->setScene(dashboard);
            }
            if (prenom=="FLORIAN"){
                delete dashboard;
                dashboard = new SceneFlorian;
                ui->graphicsView->setScene(dashboard);
            }
            if (prenom=="KARIM"){
                delete dashboard;
                dashboard = new karim_scene;
                ui->graphicsView->setScene(dashboard);
            }

            if (prenom=="LOTO"){
                delete dashboard;
                dashboard = new loto_scene;
                ui->graphicsView->setScene(dashboard);
            }

            if (prenom=="INNA"){
                delete dashboard;
                dashboard = new inna_scene;
                ui->graphicsView->setScene(dashboard);
            }
            ui->graphicsView->fitInView(ui->graphicsView->scene()->sceneRect(), Qt::KeepAspectRatio);
            ui->graphicsView->scene()->update();
            km_parcourus=0;
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
    else if(message=="CANN ASD"){
        int asd_on = string.section(' ', 2,2).toInt();
        if(asd_on==0 || asd_on==1){
            dashboard->AdaptiveSuspensionDampers->setValue(asd_on);
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
    else if(message=="CANN MODE"){
        int mode = string.section(' ', 2,2).toInt();

        if(mode >=1 && mode <= 4)
        { dashboard->AutomaticTransmissionMode->setValue(mode);
            ui->graphicsView->scene()->update();
            QString text = "OK";
            socket->write(text.toUtf8());
        }
        else{
            QString text;
            text = QString("valeur incorrect, valeur entre 1 et 4").arg(dashboard->Essence->getValueMax());
            socket->write(text.toUtf8());
        }
    }
    else if(message=="CANN FRONT_FOG"){
        int front_fog_on = string.section(' ', 2,2).toInt();
        if(front_fog_on==0 || front_fog_on==1){
            dashboard->FrontAntifog->setValue(front_fog_on);
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
    else if(message=="CANN REAR_FOG"){
        int rear_fog_on = string.section(' ', 2,2).toInt();
        if(rear_fog_on==0 || rear_fog_on==1){
            dashboard->RearAntifog->setValue(rear_fog_on);
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
    else if(message=="CANN SEAT_BELT"){
        int seatBelt_on = string.section(' ', 2,2).toInt();
        if(seatBelt_on==0 || seatBelt_on==1){
            dashboard->SeatBelt->setValue(seatBelt_on);
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
    else if(message=="CANN RW_HEAT"){
        int rwHeat_on = string.section(' ', 2,2).toInt();
        if(rwHeat_on==0 || rwHeat_on==1){
            dashboard->RearWindowHeating->setValue(rwHeat_on);
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
    else if(message=="CANN CHECK_ENGINE"){
        int checkEngine_on = string.section(' ', 2,2).toInt();
        if(checkEngine_on==0 || checkEngine_on==1){
            dashboard->CheckEngine->setValue(checkEngine_on);
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
    else if(message=="CANN ACCELERATION"){
        int time = string.section(' ', 2,2).toInt();
        if(time>0){
            acceleration(1.0*time);
            QString text = "OK";
            socket->write(text.toLocal8Bit());
        }
        else{
            QString text;
            text = QString("valeur incorrecte, doit être supérieur à 0");
            socket->write(text.toLocal8Bit());
        }
    }


    else if(message=="CANN OPEN_DOOR_DRIVER")
    {
        int OpenDoorDriver_on= string.section(' ', 2,2).toInt();
        if(OpenDoorDriver_on==0 || OpenDoorDriver_on==1){
            dashboard->OpenDoorDriver->setValue(OpenDoorDriver_on);
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
    else if(message=="CANN OPEN_DOOR_FRONT_PASSENGER")
    {
        int OpenDoorFrontPassenger_on= string.section(' ', 2,2).toInt();
        if(OpenDoorFrontPassenger_on==0 || OpenDoorFrontPassenger_on==1){
            dashboard->OpenDoorFrontPassenger->setValue(OpenDoorFrontPassenger_on);
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
    else if(message=="CANN OPEN_DOOR_FRONT_PASSENGER")
    {
        int OpenDoorFrontPassenger_on= string.section(' ', 2,2).toInt();
        if(OpenDoorFrontPassenger_on==0 || OpenDoorFrontPassenger_on==1){
            //  dashboard->OpenDoorDriver->setValue(OpenDoorDriver_on);
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
    else if(message=="CANN OPEN_DOOR_BACK_L_PASSENGER")
    {
        int OpenDoorBackLeftPassenger_on= string.section(' ', 2,2).toInt();
        if(OpenDoorBackLeftPassenger_on==0 || OpenDoorBackLeftPassenger_on==1){
            dashboard->OpenDoorBackLeftPassenger->setValue(OpenDoorBackLeftPassenger_on);
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

    else if(message=="CANN OPEN_DOOR_BACK_R_PASSENGER")
    {
        int OpenDoorBackRightPassenger_on= string.section(' ', 2,2).toInt();
        if(OpenDoorBackRightPassenger_on==0 || OpenDoorBackRightPassenger_on==1){
            dashboard->OpenDoorBackRightPassenger->setValue(OpenDoorBackRightPassenger_on);
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

    else if(message=="CANN CRUISE_CONTROL")
    {
        int cruiseControl_on= string.section(' ', 2,2).toInt();
        if(cruiseControl_on==0 || cruiseControl_on==1){
            dashboard->AdaptiveCruiseControl->setValue(cruiseControl_on);
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

    else if(message=="CANN AIRBAG_ON")
    {
        int airbag_on= string.section(' ', 2,2).toInt();
        if(airbag_on==0 || airbag_on==1){
            dashboard->AirbagOn->setValue(airbag_on);
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

    else if(message=="CANN BONNET_OPEN")
    {
        int bonnetOpen_on= string.section(' ', 2,2).toInt();
        if(bonnetOpen_on==0 || bonnetOpen_on==1){
            dashboard->BonnetOpen->setValue(bonnetOpen_on);
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

    else if(message=="CANN BOOT_OPEN")
    {
        int bootOpen_on= string.section(' ', 2,2).toInt();
        if(bootOpen_on==0 || bootOpen_on==1){
            dashboard->BootOpen->setValue(bootOpen_on);
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

    else if(message=="CANN CRUISE_CONTROL_ON")
    {
        int CruiseControlOn_on= string.section(' ', 2,2).toInt();
        if(CruiseControlOn_on==0 || CruiseControlOn_on==1){
            dashboard->CruiseControlOn->setValue(CruiseControlOn_on);
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
    else if(message=="CANN ENGINE_T"){
        int engineT = string.section(' ', 2,2).toInt();

        if(engineT <= dashboard->jaugeTemperature->getValueMax())
        { dashboard->jaugeTemperature->setValue(engineT);
            ui->graphicsView->scene()->update();
            QString text = "OK";
            socket->write(text.toUtf8());
        }
        else{
            QString text;
            text = QString("valeur incorrecte, la valeur doit être inférieure a %1").arg(dashboard->jaugeTemperature->getValueMax());
            socket->write(text.toUtf8());
        }
    }
    else if(message=="CANN OIL_T"){
        int oilT = string.section(' ', 2,2).toInt();

        if(oilT <= dashboard->OilTemp->getValueMax())
        { dashboard->OilTemp->setValue(oilT);
            ui->graphicsView->scene()->update();
            QString text = "OK";
            socket->write(text.toUtf8());
        }
        else{
            QString text;
            text = QString("valeur incorrecte, la valeur doit être inférieure a %1").arg(dashboard->OilTemp->getValueMax());
            socket->write(text.toUtf8());
        }
    }
    else if(message=="CANN OIL_L"){
        int oil = string.section(' ', 2,2).toInt();
        if(oil>=0 && oil <= dashboard->oilLevel->getValueMax()){
            dashboard->oilLevel->setValue(oil);
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
    else if(message=="CANN SPEED_LIMIT"){
        int speed_limit = string.section(' ', 2, 2).toInt();
        if(speed_limit > 0 && speed_limit <= dashboard->SpeedLimit->getValueMax()){
            dashboard->SpeedLimit->setValue(speed_limit);
            ui->graphicsView->scene()->update();
            QString text = "OK";
            socket->write(text.toLocal8Bit());
        }
        else{
            QString text;
            text = QString("valeur incorrecte, la valeur doit être comprise entre 1 et %1").arg(dashboard->Vitesse->getValueMax());
            socket->write(text.toLocal8Bit());
        }
    }
    else{
        qDebug() << "erreur lors de la reception du message";
    }
}

//A laisser commenté, peut poser problème pour certains dashboards
void MainWindow::update_km()
{
    km_parcourus+=1.0*(vitesse_actuelle)/3600;
    if (dashboard->CompteurKm)
         dashboard->CompteurKm->setValue(km_parcourus);
        ui->graphicsView->scene()->update();

    if (dashboard->CompteurKm) //
        // dashboard->CompteurKm->setValue(km_parcourus);
        ui->graphicsView->scene()->update();

}

//permet d'ajuster la taille de la scène (en fonction de boundingRect) chaque fois que MainWindow est redimensionnée
void MainWindow::resizeEvent(QResizeEvent *)
{
    ui->graphicsView->fitInView(ui->graphicsView->scene()->sceneRect(), Qt::KeepAspectRatio);
}


