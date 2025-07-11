#ifndef PLANETA_H
#define PLANETA_H

#include <QPointF>
#include <QColor>

class Planeta
{
public:
    double posX, posY;
    double velX, velY;
    double masa, radio;
    QColor color;
    Planeta(double posX_, double posY_, double velX_, double velY_, double masa_, double radio_, QColor color_);

    QPointF calculoFuerza(const Planeta* p, double gravedad) const;
    void actualizar(double fuerzaX, double fuerzaY, double tiempo);
};

#endif // PLANETA_H
