#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QGraphicsItem>
#include <QRectF>
#include <QDebug>
#include <QPushButton>
#include "pac.h"
#include "muro.h"
#include "comida.h"
#include "fantasmas.h"
#include "comidaespecial.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:
    void iniciarJuego();
    void on_btnSalir_clicked();
    void on_btnJugar_clicked();
    void volver();

private:
    Ui::Widget *ui;
    QGraphicsScene *Inicio;
    QGraphicsScene *scene;
    QGraphicsTextItem *puntos;
    QGraphicsTextItem *vidastext;
    Pac *PacMan;
    float x, y, ancho, alto;
    Muro *muro;
    Comida *comida;
    Fantasmas *fantasmarojo;
    Fantasmas *fantasmarosa;
    Fantasmas *fantasmaamarillo;
    Fantasmas *fantasmaazul;
    ComidaEspecial *comidaespecial;
};
#endif // WIDGET_H
