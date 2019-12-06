#ifndef JONAS_COMPTEUR_H
#define JONAS_COMPTEUR_H

#include <QGraphicsItem>
#include <QPainter>
#include "objet_virtuel.h"

class Jonas_compteur : public objet_virtuel
{
public:
    Jonas_compteur();
    Jonas_compteur(int valueMax, float startAngle, float endAngle, int critical, QString textOnCenter, int nGrad, bool hasExtLine = 1, bool hasSubLine = 0,  int mod = 1, int gaugeSize = 150, QStringList textOnGraduations = QStringList(), bool gradient=1);
    QRectF boundingRect() const override;
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*) override;
    void setTextOnCenter(QString newText);
    void setAlphaAngle(float newAngle);
    void setBetaAngle(float newAngle);
    void setNGrad(int n);
    void setHSubLine(bool b);
    void setHExtLine(bool b);
    void setMod(int n);
    void setGaugeSize(int size);
    float getAlpha() const;
    float getBeta() const;
    int getGaugeSize() const;
    float speedToAngle(float); // convert speed value entered to the needed angle
    QStringList addList(int);

private:
    float alpha;
    float beta;
    int gaugeSize;
    int nGrad;
    int mod;
    int critical;
    bool hExtLine;
    bool hSubLine;
    bool gradient;
    QString textOnCenter;
    QStringList textOnGraduations;
};

#endif // JONAS_COMPTEUR_H


