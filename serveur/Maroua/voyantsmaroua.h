#ifndef VOYANTSMAROUA_H
#define VOYANTSMAROUA_H
#include "objet_virtuel.h"
#include <QPainter>

class VoyantsMaroua : public objet_virtuel
{

public:
    VoyantsMaroua(QString , int, int , int);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    int x;
    int y;
    int size;
    QString path;


};

#endif // VOYANTSMAROUA_H
