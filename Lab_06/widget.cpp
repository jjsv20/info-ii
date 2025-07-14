#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->x->setMinimum(-10000);
    ui->x->setMaximum(10000);
    ui->x->setDecimals(2);

    ui->y->setMinimum(-10000);
    ui->y->setMaximum(10000);
    ui->y->setDecimals(2);

    ui->vx->setMinimum(-1000);
    ui->vx->setMaximum(1000);
    ui->vx->setDecimals(2);

    ui->vy->setMinimum(-1000);
    ui->vy->setMaximum(1000);
    ui->vy->setDecimals(2);

    ui->m->setMinimum(0.1);     // masa no debe ser negativa
    ui->m->setMaximum(100000);  // masa muy grande
    ui->m->setDecimals(2);

    ui->r->setMinimum(1);       // radio no debe ser cero
    ui->r->setMaximum(1000);
    ui->r->setDecimals(2);


    escena = new QGraphicsScene(this);
    ui->graphicsView->setScene(escena);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag); //cámara
    ui->graphicsView->setSceneRect(-10000, -10000, 20000, 20000);
    ui->graphicsView->scale(0.05, -0.05);


    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Widget::simular);

    ui->tabla->setColumnCount(7);
    ui->tabla->setHorizontalHeaderLabels(QStringList()
        << "Cuerpo"
        << "Posición X inicial"
        << "Posición Y inicial"
        << "Masa"
        << "Radio"
        << "Velocidad X inicial"
        << "Velocidad Y inicial"
    );
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_agregar_clicked()
{
    double posicionX = ui->x->value();
    double posicionY = ui->y->value();
    double velocidadX = ui->vx->value();
    double velocidadY = ui->vy->value();
    double masa = ui->m->value();
    double radio = ui->r->value();

    QColor color = QColor::fromRgb(rand()%255, rand()%255, rand()%255);

    Planeta *p = new Planeta(posicionX, posicionY, velocidadX, velocidadY, masa, radio, color);
    planetas.append(p);

    dibujarPlaneta(p);

    int fila = ui->tabla->rowCount();
    ui->tabla->insertRow(fila);

    ui->tabla->setItem(fila, 0, new QTableWidgetItem(QString::number(fila + 1)));
    ui->tabla->setItem(fila, 1, new QTableWidgetItem(QString::number(posicionX)));
    ui->tabla->setItem(fila, 2, new QTableWidgetItem(QString::number(posicionY)));
    ui->tabla->setItem(fila, 3, new QTableWidgetItem(QString::number(masa)));
    ui->tabla->setItem(fila, 4, new QTableWidgetItem(QString::number(radio)));
    ui->tabla->setItem(fila, 5, new QTableWidgetItem(QString::number(velocidadX)));
    ui->tabla->setItem(fila, 6, new QTableWidgetItem(QString::number(velocidadY)));

}


void Widget::on_limpiar_clicked()
{
    timer->stop();
    escena->clear();
    planetas.clear();
    planetasGraficos.clear();

    ui->tabla->setRowCount(0);
}


void Widget::on_simular_clicked()
{
    timer->start(16);
}


void Widget::on_pausar_clicked()
{
    timer->stop();
}

void Widget::simular()
{
    QVector<QPointF> fuerzas(planetas.size(), QPointF(0, 0));

    const double G = 1.0;
    const double dt = 2.0;

    for (int i = 0; i < planetas.size(); ++i) {
        for (int j = 0; j < planetas.size(); ++j) {
            if (i == j) continue;
            fuerzas[i] += planetas[i]->calculoFuerza(planetas[j], G);
        }
    }

    for (int i = 0; i < planetas.size(); ++i) {
        planetas[i]->actualizar(fuerzas[i].x(), fuerzas[i].y(), dt);

        QGraphicsEllipseItem *traza = escena->addEllipse(
            planetas[i]->posX,
            planetas[i]->posY,
            20, 20,
            QPen(Qt::NoPen),
            QBrush(planetas[i]->color)
        );
        traza->setZValue(-1);

        double radioVisual = 500;
        planetasGraficos[i]->setRect(
            planetas[i]->posX - radioVisual / 2,
            planetas[i]->posY - radioVisual / 2,
            radioVisual,
            radioVisual
        );
    }
}

void Widget::agregarFila()
{

}

void Widget::dibujarPlaneta(Planeta *p)
{
    double radioVisual = 500;
    QGraphicsEllipseItem *planeta = escena->addEllipse(
        p->posX - radioVisual / 2,
        p->posY - radioVisual / 2,
        radioVisual,
        radioVisual,
        QPen(Qt::black),
        QBrush(p->color)
        );
    planetasGraficos.append(planeta);
}

