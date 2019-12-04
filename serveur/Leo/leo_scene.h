#ifndef LEO_SCENE_H
#define LEO_SCENE_H

#include "leo_indicator.h"
#include "leo_label.h"
#include "scene_globale.h"

class Leo_scene : public scene_globale
{
    typedef std::vector<std::pair<objet_virtuel**,QString>> indicators_t;
    typedef std::vector<std::tuple<objet_virtuel**,int,int,QString>> gauges_t;
public:
    Leo_scene(scene_globale* parent = nullptr);
private:
    void mAddGauges(
        qreal ax,
        qreal ay,
        gauges_t gauge,
        qreal sizePx = 300,
        qreal spacingPx = 325
    );
    void mAddIndicators(
        qreal ax,
        qreal ay,
        indicators_t indicators,
        QColor colorOff = Qt::darkGreen,
        QColor colorOn = Qt::green,
        qreal spacingPx = 40
    );
};

#endif // LEO_SCENE_H
