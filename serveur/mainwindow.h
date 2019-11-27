#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include "Hugo/hugo_scene.h"

#include "compteur.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void connexion();
    void reception();
    void update_time_clignotant_droit();
    void update_km();
private:
   // Compteur * c;
    hugo_scene *dashboard;
    Ui::MainWindow *ui;
    QTcpServer * server;
    QTcpSocket * socket;
    QTimer *updateTimer;


    float km_parcourus=0;
    int vitesse_actuelle=0;
};

#endif // MAINWINDOW_H
