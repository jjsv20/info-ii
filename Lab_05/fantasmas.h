#ifndef FANTASMAS_H
#define FANTASMAS_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QPixmap>
#include "muro.h"
#include "pac.h"

class Fantasmas : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Fantasmas(QString rutaSprite, QObject *parent = nullptr);

    QTimer *timer, *salidajaula;
    bool encerrado;
    QPixmap *pixmap;

    float filas, columnas;
    float ancho, alto, escala;

    QPainterPath shape() const override;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void setPacColision(Pac* pacman);
    void detener();
    void reiniciarF();
    void guardarPosicionInicial();
    void start();
    static void setListaFantasmas(const QList<Fantasmas*>& lista);
    static QList<Fantasmas*> listaFantasmas;

signals:
public slots:
    //void actualizar();
    void mover();

private:
    int direccion;
    Pac *pacColision = nullptr;
    QPointF posicionInicial;
    QString rutaSprite;
};

#endif // FANTASMAS_H
