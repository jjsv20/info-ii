#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    scene = new QGraphicsScene;
    scene->setSceneRect(0, 0, 571, 581);

    puntos = new QGraphicsTextItem("Score: 0");
    puntos->setDefaultTextColor(Qt::yellow);
    puntos->setFont(QFont("Arial",12));
    puntos->setPos(10, 560);
    scene->addItem(puntos);

    PacMan = new Pac();
    scene->addItem(PacMan);
    PacMan->setPos(255, 432);
    PacMan->setFlag(QGraphicsItem::ItemIsFocusable);
    PacMan->setFocus();

    int mapa[25][23] = {
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,1,1,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,1,1,0,1},
        {1,0,1,1,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,1,1,0,1},
        {1,0,1,1,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,1,1,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,1,1,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,1,1,0,1},
        {1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1},
        {1,1,1,1,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,1,1,1,1},
        {2,2,2,2,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,2,2,2,2},
        {2,2,2,2,1,0,1,0,1,1,1,2,1,1,1,0,1,0,1,2,2,2,2},
        {1,1,1,1,1,0,1,0,1,2,2,2,2,2,1,0,1,0,1,1,1,1,1},
        {0,0,0,0,0,0,0,0,1,2,2,2,2,2,1,0,0,0,0,0,0,0,0},
        {1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1},
        {2,2,2,2,1,0,1,0,2,2,2,2,2,2,2,0,1,0,1,2,2,2,2},
        {2,2,2,2,1,0,1,0,2,2,2,2,2,2,2,0,1,0,1,2,2,2,2},
        {1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,1,1,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,1,1,0,1},
        {1,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,1,0,0,0,1},
        {1,1,1,0,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,0,1,1,1},
        {1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1},
        {1,0,1,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,1,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };

    for (int fila = 0; fila < 25; ++fila) {
        for (int col = 0; col < 23; ++col) {
            if (mapa[fila][col] == 1) {
                int x = col * 22 + 2;
                int y = fila * 22 + 2;
                muro = new Muro(x, y, 20, 20);
                //muro->setPos(x, y);
                scene->addItem(muro);
            }else if(mapa[fila][col] == 0){
                int x = col * 22 + (22 - 6) / 2;
                int y = fila * 22 + (22 - 6) / 2;
                comida = new Comida(x, y);
                //comida->setPos(x,y);
                scene->addItem(comida);
            }
        }
    }

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    PacMan->setPuntos(puntos);

}



Widget::~Widget()
{
    delete ui;
}
