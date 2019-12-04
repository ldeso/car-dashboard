#include "leo_label.h"

Leo_label::Leo_label(const QString &text, QPointF pos, QGraphicsItem* parent)
    : QGraphicsSimpleTextItem(text, parent)
{
    SetFontSizePx(mFontSizePx);
    setPos(pos);
}

void Leo_label::SetFontSizePx(const int fontSizePx)
{
    mFontSizePx = fontSizePx;
    QFont new_font = font();
    new_font.setPixelSize(mFontSizePx);
    setFont(new_font);
}
