#ifndef AIGUILLE_LEA_H
#define AIGUILLE_LEA_H
#include <QGraphicsItem>
#include <QRectF>

class aiguille_Lea : public QGraphicsItem
{
public:
    aiguille_Lea(QGraphicsItem *parent = nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    double x;
    double y;
    double r;
    double taille_aiguille;
    int vitesse;
    int vitesse_max;
    int angle_depart=0;
    int angle_fin=0;
    int angle =0;
    int getValueMax();
    void setValue(int);
    const double pi=3.14159265359;



    virtual void parametrage(double param_x,double param_y, double param_r, double param_t ,int param_start, int param_end, int param_value );
};

#endif // AIGUILLE_LEA_H
