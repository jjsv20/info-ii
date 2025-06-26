#include "fantasmas.h"
#include <QGraphicsScene>
#include <QDebug>

Fantasmas::Fantasmas(QString rutaSprite, QObject *parent) : QObject{parent}
{
    timer = new QTimer();
    filas = 0;
    columnas = 0;
    pixmap = new QPixmap(rutaSprite);

    ancho = 30;
    alto = 30;

    escala = 16.0 / 30.0;


    direccion = rand() % 4;
    timer->start(250);
    connect(timer, &QTimer::timeout, this, &Fantasmas::mover);
}

QPainterPath Fantasmas::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

QRectF Fantasmas::boundingRect() const
{
    return QRectF(0, 0, ancho * escala, alto * escala);
}

void Fantasmas::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->save();
    painter->scale(escala, escala);
    painter->drawPixmap(0, 0, *pixmap);
    painter->restore();
}

void Fantasmas::setPacColision(Pac *pacman)
{
    pacColision = pacman;
}


void Fantasmas::mover()
{
    QPointF posAnterior = pos();
    switch (direccion) {
    case 0: setPos(x() - 10, y()); break;
    case 1: setPos(x() + 10, y()); break;
    case 2: setPos(x(), y() - 10); break;
    case 3: setPos(x(), y() + 10); break;
    }
    for (QGraphicsItem* item : collidingItems()) {
        if (dynamic_cast<Muro*>(item)) {
            setPos(posAnterior);
            direccion = rand() % 4;
            return;
        }
        if(pacColision && item == pacColision){
            qDebug() << "colision fantasma - pacman";
            break;
        }
    }
}
