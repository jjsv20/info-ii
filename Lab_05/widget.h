#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
//#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QRectF>
#include <QDebug>
#include "pac.h"
#include "muro.h"
#include "comida.h"

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

private:
    Ui::Widget *ui;
    QGraphicsScene *scene;
    QGraphicsTextItem *puntos;
    Pac *PacMan;
    //Pac *pac;
    float x, y, ancho, alto;
    Muro *muro;
    Comida *comida;
};
#endif // WIDGET_H
