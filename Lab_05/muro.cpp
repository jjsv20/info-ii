#include "muro.h"

Muro::Muro(qreal x0, qreal y0, qreal ancho, qreal alto)
{
    setPos(x0, y0);
    rect = QRect(0, 0, ancho, alto);
}

QRectF Muro::boundingRect() const
{
    return rect;
}

void Muro::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::blue);
    painter->drawRect(rect);
}





