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

    int valeur;//la vitesse actualisée
    int valeurMax;//la vitesse maximum
};

#endif // CADRANTVIRTUEL_H
