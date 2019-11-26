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
private:
   // Compteur * c;
    hugo_scene *dashboard;
    Ui::MainWindow *ui;
    QTcpServer * server;
    QTcpSocket * socket;
};

#endif // MAINWINDOW_H
