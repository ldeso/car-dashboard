#include "leo_gauge.h"
#include "leo_limit.h"
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

    template <class T>
    void AddObjects(Leo_scene* scene, const std::vector<Object> objects)
    {
        for (Object obj : objects) {
            *obj.object = new T(obj.rect);
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
    AddObjects<Leo_gauge>(
        this,
        {
            {
                &CompteTours,
                QRectF(0, 0, 200, 200),
                {
                    { Leo_gauge::MAX, 8000 },
                    { Leo_gauge::DIVS, 4 },
                    { Leo_gauge::SUBDIVS, 8 },
                    { Leo_gauge::STARTANGLE, -145 },
                    { Leo_gauge::ARCLENGTH, -155 }
                }
            },
            {
                &Vitesse,
                QRectF(135, 0, 200, 200),
                {
                    { Leo_gauge::MAX, 260 },
                    { Leo_gauge::DIVS, 13 },
                    { Leo_gauge::SUBDIVS, 26 },
                }
            },
            { &oilLevel, QRectF(60, 130, 70, 70), {} },
            { &Essence, QRectF(200, 130, 70, 70), {} },
        }
    );
    AddObjects<Leo_limit>(this, {{&SpeedLimit, QRectF(210, 40, 50, 50), {}}});
}
