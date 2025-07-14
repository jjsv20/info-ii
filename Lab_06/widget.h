#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QVector>
#include <QTimer>
#include "planeta.h"

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
    void on_agregar_clicked();

    void on_limpiar_clicked();

    void on_simular_clicked();

    void on_pausar_clicked();

    void simular();

private:
    Ui::Widget *ui;
    QGraphicsScene *escena;
    QVector<Planeta*> planetas;
    QVector<QGraphicsEllipseItem*> planetasGraficos;
    QTimer* timer;

    void dibujarPlaneta(Planeta *p);
};
#endif // WIDGET_H
