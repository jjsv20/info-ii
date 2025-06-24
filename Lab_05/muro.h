#ifndef MURO_H
#define MURO_H

#include <QObject>
#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>
#include <QKeyEvent>

class Muro : public QGraphicsObject
{
    Q_OBJECT
public:
    Muro(qreal x0, qreal y0, qreal ancho, qreal alto);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    QRectF rect;
};

#endif // MURO_H
