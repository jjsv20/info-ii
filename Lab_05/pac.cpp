#include "pac.h"
#include "muro.h"
#include "comida.h"
#include "comidaespecial.h"
#include "fantasmas.h"

Pac::Pac(QObject *parent) : QObject(parent)
{
    filas = 0;
    columnas = 0;
    pixmap = new QPixmap(":/imagenes/pac.png");

    ancho = 15;
    alto = 15;

    posicionInicial = QPointF(245, 425);
    setPos(posicionInicial);
}

void Pac::setPuntos(QGraphicsTextItem* texto) {
    puntos = texto;
}

void Pac::setVidasText(QGraphicsTextItem *texto)
{
    vidastext = texto;
}

void Pac::actualizar()
{
    columnas += 15;
    if(columnas >= 45){
        columnas = 0;
    }
    this->update(0, 0, ancho, alto);
}

void Pac::colisionComida()
{
    const auto items = scene()->items();
    for(auto i : items){
        if(Comida* comida = dynamic_cast<Comida*>(i)){
            if(collidesWithItem(comida)){
                scene()->removeItem(comida);
                delete comida;
                contadorComida += 10;
                if(puntos){
                    puntos->setPlainText("Score: " + QString::number(contadorComida));
                }
            }
        }else if(ComidaEspecial* comidaEspecial = dynamic_cast<ComidaEspecial*>(i)){
            if(collidesWithItem(comidaEspecial)){
                scene()->removeItem(comidaEspecial);
                delete comidaEspecial;
                contadorComida += 50;
                if(puntos){
                    puntos->setPlainText("Score: " + QString::number(contadorComida));
                }
            }
        }
    }
}

void Pac::spriteMuerte()
{
    if(estaMuerto){
        return;
    }

    estaMuerto = true;
    columnas = 0;
    filas = 0;
    ancho = 18.5;
    alto = 15;
    cuadros = 0;
    pixmap = new QPixmap(":/imagenes/muerte.png");

    muerte = new QTimer();
    connect(muerte, &QTimer::timeout, [=]() {
        columnas = cuadros * ancho;
        update(0, 0, ancho, alto);
        cuadros++;
        if (cuadros >= 4) {
            delete muerte;
            muerte = nullptr;
            perderVida();
            qDebug() << "Pac-Man ha muerto.";
            QTimer::singleShot(1000, [=](){
                reiniciar();
                for (Fantasmas* f : Fantasmas::listaFantasmas) {
                    f->reiniciarF();
                    f->start();
                }
            });
        }
    });
    muerte->start(50);
}

QRectF Pac::boundingRect() const
{
    return QRectF(0, 0, ancho, alto);
}

void Pac::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0, 0, *pixmap, columnas, filas, ancho, alto);

}

void Pac::reiniciar()
{
    estaMuerto = false;
    columnas = 0;
    filas = 0;
    ancho = 15;
    alto = 15;
    pixmap = new QPixmap(":/imagenes/pac.png");
    setPos(posicionInicial);
    update();
}

void Pac::perderVida()
{
    if (vidas > 0) {
        vidas--;
        if (vidastext) {
            vidastext->setPlainText("Vidas: " + QString::number(vidas));
        }
    }
    if(vidas > 0){
        estaMuerto = false;
        columnas = 0;
        filas = 0;
        ancho = 16;
        alto = 16;
        setPos(posicionInicial);
        update();
    }else {
        qDebug() << "¡Game Over!";
        emit reiniciarPartida();
    }
}


void Pac::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_D: moverDerecha(); qDebug() << "Tecla: D"; break;
    case Qt::Key_A: moverIzquierda(); qDebug() << "Tecla: A"; break;
    case Qt::Key_Z: moverAbajo(); qDebug() << "Tecla: Z"; break;
    case Qt::Key_S: moverArriba(); qDebug() << "Tecla: S"; break;
        //default: QGraphicsObject::keyPressEvent(event);
    }
}

void Pac::moverDerecha() {
    filas = 0;
    columnas += 60;
    if(columnas >= 90){
        columnas = 0;
    }
    this->update(0, 0, ancho, alto);
    QPointF posAnterior = pos();
    setPos(x() + 10, y());
    if(x() > scene()->width()){
        setPos(0, y());
    }

    for (QGraphicsItem* item : collidingItems()) {
        if (dynamic_cast<Muro*>(item)) {
            setPos(posAnterior);
            return;
        }
    }
    colisionComida();
}

void Pac::moverIzquierda() {
    columnas += 15;
    if(columnas >= 30){
        columnas = 0;
    }
    this->update(0, 0, ancho, alto);

    QPointF posAnterior = pos();
    setPos(x() - 10, y());
    if (x() + boundingRect().width() < 0) {
        setPos(scene()->width() - boundingRect().width(), y());
    }

    for (QGraphicsItem* item : collidingItems()) {
        if (dynamic_cast<Muro*>(item)) {
            setPos(posAnterior);
            return;
        }
    }
    colisionComida();
}


void Pac::moverArriba() {
    columnas += 105;
    if(columnas >= 150){
        columnas = 0;
    }
    this->update(0, 0, ancho, alto);
    QPointF posAnterior = pos();
    setPos(x(), y() - 10);

    for (QGraphicsItem* item : collidingItems()) {
        if (dynamic_cast<Muro*>(item)) {
            setPos(posAnterior);
            return;
        }
    }
    colisionComida();
}

void Pac::moverAbajo() {
    columnas += 150;
    if(columnas >= 180){
        columnas = 0;
    }
    this->update(0, 0, ancho, alto);
    QPointF posAnterior = pos();
    setPos(x(), y() + 10);

    for (QGraphicsItem* item : collidingItems()) {
        if (dynamic_cast<Muro*>(item)) {
            setPos(posAnterior);
            return;
        }
    }
    colisionComida();
}

QPainterPath Pac::shape() const {
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}
