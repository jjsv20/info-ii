#ifndef PAC_H
#define PAC_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QPixmap>
#include <QRectF>
#include <QPainter>
#include <QKeyEvent>
#include <QDebug>

class Pac : public QGraphicsObject
{
    Q_OBJECT
public:
    Pac(qreal x0, qreal y0);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    QTimer *timer;
    QPixmap *pixmap;

signals:
public slots:
    //void actualizar();

protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    void moverDerecha();
    void moverIzquierda();
    void moverAbajo();
    void moverArriba();
    int contadorComida = 0;
};


#endif // PAC_H
