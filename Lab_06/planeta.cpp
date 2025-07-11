#include "planeta.h"
#include <cmath>

Planeta::Planeta(double posX_, double posY_, double velX_, double velY_, double masa_, double radio_, QColor color_)
    : posX(posX_), posY(posY_), velX(velX_), velY(velY_), masa(masa_), radio(radio_), color(color_)
{

}

QPointF Planeta::calculoFuerza(const Planeta *planeta, double gravedad) const
{
    double x = planeta->posX - posX;
    double y = planeta->posY - posY;
    double distancia = std::sqrt(x * x + y * y) + 1e-5;

    double fuerza = (gravedad * masa * planeta->masa) / (distancia * distancia);

    double fX = fuerza * (x / distancia);
    double fY = fuerza * (y / distancia);

    return QPointF(fX, fY);
}

void Planeta::actualizar(double fuerzaX, double fuerzaY, double tiempo)
{
    double ax = fuerzaX / masa;
    double ay = fuerzaY / masa;

    velX += ax * tiempo; //vx=vx0+axt
    velY += ay * tiempo; //vy=vy0+ayt

    posX += velX * tiempo + 0.5 * ax * tiempo * tiempo; //x=x0+vxt + 0.5*ax*t*t
    posY += velY * tiempo + 0.5 * ay * tiempo * tiempo; //y=y0+vyt + 0.5*ayt*t
}
