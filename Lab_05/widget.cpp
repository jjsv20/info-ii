#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent): QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::iniciarJuego()
{
    ui->stackedWidget->setCurrentIndex(1);

    scene = new QGraphicsScene;
    scene->setSceneRect(0, 0, 508, 618);

    puntos = new QGraphicsTextItem("Score: 0");
    puntos->setDefaultTextColor(Qt::yellow);
    puntos->setFont(QFont("Arial",12));
    puntos->setPos(10, 560);
    scene->addItem(puntos);

    vidastext = new QGraphicsTextItem("Vidas: 3");
    vidastext->setDefaultTextColor(Qt::yellow);
    vidastext->setFont(QFont("Arial",12));
    vidastext->setPos(120, 560);
    scene->addItem(vidastext);

    PacMan = new Pac();
    scene->addItem(PacMan);
    PacMan->setPos(245, 425);
    PacMan->setFlag(QGraphicsItem::ItemIsFocusable);
    PacMan->setFocus();
    connect(PacMan, &Pac::reiniciarPartida, this, &Widget::volver);

    int mapa[25][23] = {
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,1,1,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,1,1,0,1},
        {1,3,1,1,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,1,1,3,1},
        {1,0,1,1,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,1,1,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,1,1,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,1,1,0,1},
        {1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1},
        {1,1,1,1,1,0,1,1,1,1,2,1,2,1,1,1,1,0,1,1,1,1,1},
        {2,2,2,2,1,0,1,2,2,2,2,2,2,2,2,2,1,0,1,2,2,2,2},
        {2,2,2,2,1,0,1,2,1,1,1,2,1,1,1,2,1,0,1,2,2,2,2},
        {1,1,1,1,1,0,1,2,1,2,2,2,2,2,1,2,1,0,1,1,1,1,1},
        {2,2,2,2,2,0,2,2,1,2,2,2,2,2,1,2,2,0,2,2,2,2,2},
        {1,1,1,1,1,0,1,2,1,1,1,1,1,1,1,2,1,0,1,1,1,1,1},
        {2,2,2,2,1,0,1,2,2,2,2,2,2,2,2,2,1,0,1,2,2,2,2},
        {2,2,2,2,1,0,1,2,2,2,2,2,2,2,2,2,1,0,1,2,2,2,2},
        {1,1,1,1,1,0,1,2,1,1,1,1,1,1,1,2,1,0,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,1,1,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,1,1,0,1},
        {1,3,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,1,0,0,3,1},
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
                int x = col * 22 + (22 - 4) / 2;
                int y = fila * 22 + (22 - 4) / 2;
                comida = new Comida(x, y);
                //comida->setPos(x,y);
                scene->addItem(comida);
            }else if(mapa[fila][col] == 3){
                int x = col * 22 + (22 - 10) / 2;
                int y = fila * 22 + (22 - 10) / 2;
                comidaespecial = new ComidaEspecial(x, y);
                scene->addItem(comidaespecial);
            }
        }
    }

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    PacMan->setPuntos(puntos);
    PacMan->setVidasText(vidastext);

    fantasmarojo = new Fantasmas(":/imagenes/fantasmarojo.png");
    scene->addItem(fantasmarojo);
    fantasmarojo->setPacColision(PacMan);
    fantasmarojo->setPos(24, 381);
    fantasmarojo->guardarPosicionInicial();

    fantasmaazul = new Fantasmas(":/imagenes/fantasmaazul.png");
    scene->addItem(fantasmaazul);
    fantasmaazul->setPacColision(PacMan);
    fantasmaazul->setPos(465, 383);
    fantasmaazul->guardarPosicionInicial();

    fantasmaamarillo = new Fantasmas(":/imagenes/fantasmaamarillo.png");
    scene->addItem(fantasmaamarillo);
    fantasmaamarillo->setPacColision(PacMan);
    fantasmaamarillo->setPos(245, 113);
    fantasmaamarillo->guardarPosicionInicial();

    fantasmarosa = new Fantasmas(":/imagenes/fantasmarosa.png");
    scene->addItem(fantasmarosa);
    fantasmarosa->setPacColision(PacMan);
    fantasmarosa->setPos(100, 465);
    fantasmarosa->guardarPosicionInicial();

    QList<Fantasmas*> fantasmas = { fantasmarojo, fantasmaazul, fantasmaamarillo, fantasmarosa };
    Fantasmas::setListaFantasmas(fantasmas);
}



void Widget::on_btnSalir_clicked()
{
    close();
}


void Widget::on_btnJugar_clicked()
{
    iniciarJuego();
}

void Widget::volver()
{
    ui->stackedWidget->setCurrentIndex(0);
}

