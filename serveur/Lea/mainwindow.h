#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "mygraphicitem.h"
#include "speedometer_lea.h"
#include "tachometergauge_lea.h"
#include "fuelgauge_lea.h"
#include "voyant_lea.h"
#include "aiguille_lea.h"

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    QGraphicsView *view = new QGraphicsView();
    QGraphicsScene *scene = new QGraphicsScene ();
    mygraphicItem *myitem = new mygraphicItem ();



    ~MainWindow();

public slots :
    void Scene();



private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
