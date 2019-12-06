#ifndef VOYANTS_KARIM_H
#define VOYANTS_KARIM_H
#include <objet_virtuel.h>
#include <QGraphicsItem>
#include <QPainter>

class Voyants_karim : public objet_virtuel
{

public:
    Voyants_karim(QString , int, int , int);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    int x;
    int y;
    int size;
    QString path;

 };

#endif // VOYANTS_KARIM_H
