#ifndef AUTRESVOYANTS_H
#define AUTRESVOYANTS_H
#include <objet_virtuel.h>
#include <QGraphicsItem>
#include <QPainter>

class autresvoyants : public objet_virtuel
{
public:
    autresvoyants(QString, int, int, int);
    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private :
    int x;
    int y;
    int taille;
    QString ch;

};

#endif // AUTRESVOYANTS_H
