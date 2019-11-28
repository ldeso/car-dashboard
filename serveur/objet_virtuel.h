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

    int getValue() const;
    void setValue(int value);
    int getValueMax() const;

    QString styleTexte;

protected:
    int value;//la vitesse actualisée
    int valueMax;//la vitesse maximum
};

#endif // OBJET_VIRTUEL_H
