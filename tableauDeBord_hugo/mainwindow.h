#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QGraphicsScene>
#include "mygraphicsitem.h"
#include "aiguille.h"
#include "autoradio.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QGraphicsScene *scene;
    MyGraphicsitem *test;
    Aiguille *aiguille_vitesse;
    Aiguille *aiguille_rpm;
    Aiguille *aiguille_essence;
    Aiguille *aiguille_temperature;
    AutoRadio *radio=new AutoRadio;
    QString Current_Station;
    int volume=50;
    int radio_on=0;

    ~MainWindow();

private slots:
    void vit();
    void START();
    void NEXT();
    void PREVIOUS();
    void Vmute();
    void Vplus();
    void Vmoins();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
