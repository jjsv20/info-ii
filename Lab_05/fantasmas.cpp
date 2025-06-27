#include "fantasmas.h"
#include "pac.h"
#include <QGraphicsScene>
#include <QDebug>

Fantasmas::Fantasmas(QString rutaSprite, QObject *parent) : QObject{parent}
{
    timer = new QTimer();
    filas = 0;
    columnas = 0;
    pixmap = new QPixmap(rutaSprite);
    //this->rutaSprite = rutaSprite;

    ancho = 30;
    alto = 30;

    escala = 13.0 / 30.0;


    direccion = rand() % 4;
    timer->start(300);
    connect(timer, &QTimer::timeout, this, &Fantasmas::mover);
    //setPos(x0, y0);
    posicionInicial = pos();
}

QList<Fantasmas*> Fantasmas::listaFantasmas;
void Fantasmas::setListaFantasmas(const QList<Fantasmas *> &lista)
{
    listaFantasmas = lista;
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

void Fantasmas::detener()
{
    if(timer){
        timer->stop();
    }
}

void Fantasmas::reiniciarF()
{
    columnas = 0;
    filas = 0;
    ancho = 30;
    alto = 30;
    setPos(posicionInicial);
    update();
}

void Fantasmas::guardarPosicionInicial()
{
    posicionInicial = pos();
}

void Fantasmas::start()
{
    if(timer){
        timer->start(250);
    }
}

void Fantasmas::mover()
{
    QPointF posAnterior = pos();
    switch (direccion) {
    case 0: setPos(x() - 20, y()); break;
    case 1: setPos(x() + 20, y()); break;
    case 2: setPos(x(), y() - 20); break;
    case 3: setPos(x(), y() + 20); break;
    }
    for (QGraphicsItem* item : collidingItems()) {
        if (dynamic_cast<Muro*>(item)) {
            setPos(posAnterior);
            direccion = rand() % 4;
            return;
        }
        if(pacColision && item == pacColision){
            setPos(posAnterior);
            for(Fantasmas *f : listaFantasmas) {
                f->detener();
            }
            pacColision->spriteMuerte();
            qDebug() << "colision fantasma - pacman";
            break;
        }if(x() > scene()->width()){
            setPos(0, y());
        }
    }
}

