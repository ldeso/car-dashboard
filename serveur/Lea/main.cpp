#include "mainwindow.h"
#include <QApplication>
#include <QGraphicsScene>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.Scene();
    w.show();

    return a.exec();
}
