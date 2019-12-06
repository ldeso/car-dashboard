#include "leo_display.h"
#include "leo_gauge.h"
#include "leo_scene.h"

namespace {
    struct Data {
        int key;
        const QVariant value;
    };

    struct Object {
        objet_virtuel** object;
        QRectF rect;
        std::vector<Data> data;
    };

    void AddGauges(Leo_scene* scene, const std::vector<Object> objects)
    {
        for (Object obj : objects) {
            *obj.object = new Leo_gauge(obj.rect);
            for (Data dat : obj.data)
                (*obj.object)->setData(dat.key, dat.value);
            scene->addItem(*obj.object);
        }
    }
}

Leo_scene::Leo_scene(scene_globale* parent)
    : scene_globale(parent)
{
    setBackgroundBrush(Qt::black);
    AddGauges(
        this,
        {
            {
                &Vitesse,
                QRectF(0, 0, 200, 200),
                {
                    { Leo_gauge::MAX, 260 },
                    { Leo_gauge::DIVS, 10 },
                    { Leo_gauge::SUBDIVS, 20 }
                }
            },
            {
                &Essence,
                QRectF(65, 130, 70, 70),
                {
                    { Leo_gauge::MAX, 100 },
                    { Leo_gauge::DIVS, 2 },
                    { Leo_gauge::SUBDIVS, 4 }
                }
            },
        }
    );
}
