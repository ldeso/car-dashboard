#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include "Hugo/hugo_scene.h"
#include "Henri/henri_scene.h"
#include "Jonas/jonas_scene.h"
#include "Florian/sceneflorian.h"
#include "Lea/lea_scene.h"
#include "Leo/leo_scene.h"
#include "Karim/karim_scene.h"
#include "Loto/loto_scene.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void acceleration(int);
    ~MainWindow();

private slots:
    void connexion();
    void reception();
    void update_km();
private:
   // Compteur * c;
    scene_globale *dashboard;

    Ui::MainWindow *ui;
    QTcpServer * server;
    QTcpSocket * socket;
    QTimer *updateTimer;


    float km_parcourus=0;
    int vitesse_actuelle=0;
};

#endif // MAINWINDOW_H
