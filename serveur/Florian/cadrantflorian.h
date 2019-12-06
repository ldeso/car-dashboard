#ifndef CADRANTFLORIAN_H
#define CADRANTFLORIAN_H
#include "cadrantvirtuel.h"
#include "../objet_virtuel.h"
class CadrantFlorian : public objet_virtuel
{
public:
    CadrantFlorian(bool hasText = true, bool hasSubTrait = true, int invertAiguille = 1, int pas = 10, int angleB = 220, int angleE= 260,int valeurMax=260, bool hasGradient= true, QGraphicsItem * parent = NULL);
    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    float generateAngle();
    int getSpeedMax();
private:
    bool hasText;
    bool hasSubTrait;
    int invertAiguille;
    int pas;
    int angleB;
    int angleE;
    int width;
    int height;
    bool hasGradient;
};

#endif // CADRANTFLORIAN_H
