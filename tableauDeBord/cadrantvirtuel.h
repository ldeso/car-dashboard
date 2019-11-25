#ifndef CADRANTVIRTUEL_H
#define CADRANTVIRTUEL_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QtMath>

class cadrantVirtuel : public QGraphicsItem
{
public:
    cadrantVirtuel(QGraphicsItem *parent=nullptr);

    int vitesse;//la vitesse actualisée
    int vitesseMax;//la vitesse maximum
};

#endif // CADRANTVIRTUEL_H
