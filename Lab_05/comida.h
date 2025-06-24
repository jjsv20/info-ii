#ifndef COMIDA_H
#define COMIDA_H

#include <QObject>
#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>

class Comida : public QGraphicsObject
{
    Q_OBJECT
public:
     Comida(qreal x0, qreal y0);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    QRectF circ;
};

#endif // COMIDA_H
