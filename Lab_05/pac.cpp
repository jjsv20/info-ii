#include "pac.h"
#include "muro.h"

Pac::Pac(qreal x0, qreal y0)
{
    setPos(x0, y0);
}

QRectF Pac::boundingRect() const
{
    return QRectF(-10, -10, 16, 16);
}

void Pac::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::yellow);
    painter->drawEllipse(boundingRect());
}

void Pac::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_D: moverDerecha(); qDebug() << "Tecla: D"; break;
    case Qt::Key_A: moverIzquierda(); qDebug() << "Tecla: A"; break;
    case Qt::Key_S: moverAbajo(); qDebug() << "Tecla: S"; break;
    case Qt::Key_W: moverArriba(); qDebug() << "Tecla: W"; break;
    //default: QGraphicsObject::keyPressEvent(event);
    }
}

void Pac::moverDerecha() {
    QPointF posAnterior = pos();
    setPos(x() + 10, y());

    for (QGraphicsItem* item : collidingItems()) {
        if (dynamic_cast<Muro*>(item)) {
            setPos(posAnterior); // Revertir si choca
            return;
        }
    }
}

void Pac::moverIzquierda() {
    QPointF posAnterior = pos();
    setPos(x() - 10, y());

    for (QGraphicsItem* item : collidingItems()) {
        if (dynamic_cast<Muro*>(item)) {
            setPos(posAnterior);
            return;
        }
    }
}

void Pac::moverArriba() {
    QPointF posAnterior = pos();
    setPos(x(), y() - 10);

    for (QGraphicsItem* item : collidingItems()) {
        if (dynamic_cast<Muro*>(item)) {
            setPos(posAnterior);
            return;
        }
    }
}

void Pac::moverAbajo() {
    QPointF posAnterior = pos();
    setPos(x(), y() + 10);

    for (QGraphicsItem* item : collidingItems()) {
        if (dynamic_cast<Muro*>(item)) {
            setPos(posAnterior);
            return;
        }
    }
}




