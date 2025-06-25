#include "comida.h"

Comida::Comida(qreal x0, qreal y0)
{
    setPos(x0, y0);
}

QRectF Comida::boundingRect() const
{
    return QRectF(0, 0, 6, 6);
}

void Comida::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::white);
    painter->drawEllipse(boundingRect());
}
