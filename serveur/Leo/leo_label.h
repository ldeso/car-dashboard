#ifndef LEO_LABEL_H
#define LEO_LABEL_H

#include "objet_virtuel.h"

class Leo_label : public QGraphicsSimpleTextItem
{
public:
    Leo_label(const QString &text, QGraphicsItem* parent = nullptr);
    void SetFontSizePx(const int);
private:
    int mFontSizePx = 25;
};

#endif // LEO_LABEL_H
