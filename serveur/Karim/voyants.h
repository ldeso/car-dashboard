#ifndef VOYANTS_H
#define VOYANTS_H

#include <objet_virtuel.h>
#include <QGraphicsItem>
#include <QPainter>


class Voyants : public objet_virtuel
{

public:
    int getValue() const;
    void setValue(int value);
    int getValueMax() const;

protected:
    int valeur;
    int valeurMax;

 };

#endif // VOYANTS_H
