#include <QCompleter>
#include <cstring>

#include "mainwindow.h"
#include "ui_mainwindow.h"

extern "C" {
    #include "clientio.h"
}

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->action_Quit, &QAction::triggered, this, &MainWindow::close);
    connect(ui->lineEdit, &QLineEdit::returnPressed, this, &MainWindow::OnSend);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::OnSend);
    QStringList commands = {
        "CANN BATTERY_LIGHT ",
        "CANN DASHBOARD ",
        "CANN GAZ ",
        "CANN LIGHT ",
        "CANN RPM ",
        "CANN SPEED ",
        "CANN SPEED_LIMIT ",
        "CANN TURN ",
        "CANN WARNING ",
        "CANN ASD ",
        "CANN MODE ",
        "CANN FRONT_FOG ",
        "CANN REAR_FOG ",
        "CANN SEAT_BELT ",
        "CANN RW_HEAT ",
        "CANN CHECK_ENGINE ",
        "CANN ACCELERATION ",
        "CANN OPEN_DOOR_DRIVER ",
        "CANN OPEN_DOOR_FRONT_PASSENGER ",
        "CANN OPEN_DOOR_BACK_L_PASSENGER ",
        "CANN OPEN_DOOR_BACK_R_PASSENGER ",
        "CANN CRUISE_CONTROL ",
        "CANN AIRBAG_ON ",
        "CANN BONNET_OPEN ",
        "CANN BOOT_OPEN "
    };
    auto completer = new QCompleter(commands, this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit->setCompleter(completer);
    if ((mSockfd = create_connected_socket("127.0.0.1", 2222)) == -1)
        ui->plainTextEdit->appendPlainText(
            "Erreur lors de la connexion au serveur."
        );
    else
        ui->plainTextEdit->appendPlainText(
            "Veuillez saisir une commande à envoyer."
        );
}

MainWindow::~MainWindow()
{
    close_socket(mSockfd);
    delete ui;
}

void MainWindow::OnSend()
{
    char* sent = new char[mLen];
    std::strncpy(sent, ui->lineEdit->text().toStdString().c_str(), mLen);
    ui->lineEdit->clear();
    if (send_message(mSockfd, sent, mLen) == -1)
        ui->plainTextEdit->appendPlainText(
            "Erreur lors de l'envoi du message"
        );
    else
        if (validate_message(sent) == -1) {
            ui->plainTextEdit->appendPlainText(
                "Commande invalide."
            );
        } else {
            char* received = new char[mLen];
            std::memset(received, '\0', mLen);
            if (receive_message(mSockfd, received, mLen) == -1)
                ui->plainTextEdit->appendPlainText(
                    "Erreur lors de la réception du message"
                );
            else
                ui->plainTextEdit->appendPlainText(QString(received));
            delete[] received;
        }
    delete[] sent;
}
