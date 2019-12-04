#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "cardialerprototype.h"
#include "carspeeddial.h"
#include "tachometer.h"
#include "fuelgauge.h"
#include "engineheatgauge.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QGraphicsScene *scene;
    CarDialerPrototype *MainDial = new CarDialerPrototype();
    CarSpeedDial *Speed = new CarSpeedDial();
    Tachometer *tacho = new Tachometer();
    FuelGauge *fuel = new FuelGauge();
    EngineHeatGauge *heat = new EngineHeatGauge();

public slots :
  void Speedometer();
  void mascene();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
