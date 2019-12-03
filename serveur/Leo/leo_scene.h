#ifndef LEO_SCENE_H
#define LEO_SCENE_H

#include "leo_indicator.h"
#include "leo_label.h"
#include "scene_globale.h"

class Leo_scene : public scene_globale
{
    typedef std::vector<std::pair<objet_virtuel**,const QString>> indicators_t;
public:
    Leo_scene(scene_globale* parent = nullptr);
private:
    void mAddIndicators(
        qreal ax,
        qreal ay,
        indicators_t indicators,
        QColor colorOff = Qt::darkGreen,
        QColor colorOn = Qt::green
    );
    void mAddGauge(qreal ax, qreal ay, objet_virtuel*& gauge, int maxValue, int spacing = 20);
    qreal mRowSpacingPx = 40;
};

#endif // LEO_SCENE_H
