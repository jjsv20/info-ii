#include "comidaespecial.h"

ComidaEspecial::ComidaEspecial(qreal x0, qreal y0)
{
    setPos(x0, y0);
}

QRectF ComidaEspecial::boundingRect() const
{
    return QRectF(0, 0, 10, 10);
}

void ComidaEspecial::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::yellow);
    painter->drawEllipse(boundingRect());
}
