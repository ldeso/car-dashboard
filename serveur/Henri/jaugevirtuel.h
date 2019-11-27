#ifndef JAUGEVIRTUEL_H
#define JAUGEVIRTUEL_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QtMath>

class jaugeVirtuel : public QGraphicsItem
{
public:
    jaugeVirtuel(QGraphicsItem *parent=nullptr);
    int getValue() const;
    void setValue(int value);
    int getValueMax() const;

protected:
    int valeur;
    int valeurMax;
};

#endif // JAUGEVIRTUEL_H
