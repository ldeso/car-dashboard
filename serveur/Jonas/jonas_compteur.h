#ifndef JONAS_COMPTEUR_H
#define JONAS_COMPTEUR_H

#include <QGraphicsItem>
#include <QPainter>
#include "objet_virtuel.h"

class Jonas_compteur : public objet_virtuel
{
public:
    Jonas_compteur();
    Jonas_compteur(int max, QStringList gradList, float startAngle, float endAngle, QString textCenter, int ngrad, bool line = 0, int mod = 2, int size = 150);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*) override;
    void setTextLabel(QString newText);
    void setAlphaAngle(float newAngle);
    void setBetaAngle(float newAngle);
    void setGraduation(int n);
    void setHLine(bool b);
    void setMod(int n);
    void setGaugeSize(int size);
    float getAlpha() const;
    float getBeta() const;
    int getGaugeSize() const;
    QString gettextLabel() const;
    float speedToAngle(float); // convert speed value entered to the needed angle

private:
    float alpha;
    float beta;
    int gaugeSize;
    int graduations;
    int mod;
    bool hLine;
    QString textLabel;
    QStringList textAround;
    float valueToAngle(int) const;
};

#endif // JONAS_COMPTEUR_H


