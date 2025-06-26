#ifndef COMIDAESPECIAL_H
#define COMIDAESPECIAL_H

#include <QObject>
#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>

class ComidaEspecial : public QGraphicsObject
{
    Q_OBJECT
public:
    ComidaEspecial(qreal x0, qreal y0);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    QRectF circ;
};

#endif // COMIDAESPECIAL_H
