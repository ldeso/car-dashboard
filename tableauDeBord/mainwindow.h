#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cadranthenri.h"
#include "jaugeessence.h"
#include "scenedefond.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QGraphicsScene *scene;
    sceneDeFond *fond;
    cadrantHenri *cadrant;
    jaugeEssence *jauge;

private:
    Ui::MainWindow *ui;

private slots:
    void vit();//les fonctions pour actualiser les valeurs, qui sont connectées aux sliders.
    void tou();
    void sty(QString s);
    void ess();
};

#endif // MAINWINDOW_H
