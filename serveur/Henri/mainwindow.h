#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cadranthenri.h"
#include "jaugeessencehenri.h"
#include "scenedefondhenri.h"
#include "jaugetoursminutehenri.h"
#include "sceneglobale.h"
#include "jaugetemperature.h"
#include "jaugeclignotant.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    sceneGlobale *scene;
    void cli();

private:
    Ui::MainWindow *ui;


private slots:
    void vit();//les fonctions pour actualiser les valeurs, qui sont connectées aux sliders.
    void tou();
    void ess();
    void cli_g();
    void cli_d();
    void cli_s();
    void sty(QString t);
};

#endif // MAINWINDOW_H
