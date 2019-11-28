#ifndef HUGO_VOYANTS_H
#define HUGO_VOYANTS_H
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QtMath>


class hugo_voyants : public QGraphicsItem
{
public:
    hugo_voyants(QGraphicsItem *parent=nullptr);
    int getValue() const;
    void setValue(int value);
    int getValueMax() const;

protected:
    int valeur;
    int valeurMax;
};

#endif // HUGO_VOYANTS_H

