#include "leo_display.h"
#include "leo_gauge.h"
#include "leo_scene.h"

Leo_scene::Leo_scene(scene_globale* parent)
    : scene_globale(parent)
{
    setBackgroundBrush(Qt::black);
    Vitesse = new Leo_gauge(QRectF(0, 0, 200, 200), 260, 20, 10);
    addItem(Vitesse);
    Essence = new Leo_gauge(QRectF(65, 130, 70, 70), 100, 50, 25);
    addItem(Essence);
}
