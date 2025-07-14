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

class Pac : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Pac(QObject *parent = nullptr);

    void setPuntos(QGraphicsTextItem *texto);
    void setVidasText(QGraphicsTextItem *texto);
    QTimer *timer, *muerte;
    QPixmap *pixmap;

    bool estaMuerto = false;
    int cuadros = 0;

    float filas, columnas;
    float ancho, alto;
    QPainterPath shape() const override;

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void reiniciar();
    int getVidas() const { return vidas; }
    void perderVida();

signals:
    void reiniciarPartida();
public slots:
    void actualizar();
    void colisionComida();
    void spriteMuerte();

protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    void moverDerecha();
    void moverIzquierda();
    void moverAbajo();
    void moverArriba();
    QGraphicsTextItem *puntos;
    int contadorComida = 0;
    QPointF posicionInicial;
    QGraphicsTextItem *vidastext;
    int vidas = 3;
};


#endif // PAC_H
