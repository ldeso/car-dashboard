#ifndef OBJET_VIRTUEL_H
#define OBJET_VIRTUEL_H
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QtMath>

class objet_virtuel : public QGraphicsItem
{
public:
    objet_virtuel(QGraphicsItem *parent=nullptr);

    float getValue() const;
    void setValue(float value);
    int getValueMax() const;

    QString styleTexte;

protected:
    float value;//la vitesse actualisée
    int valueMax;//la vitesse maximum
};

#endif // OBJET_VIRTUEL_H
