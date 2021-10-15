#include "personaje.h"


int Personaje::getVidas() const
{
    return vidas;
}

void Personaje::setVidas(int value)
{
    vidas = value;
}

int Personaje::getPuntaje() const
{
    return puntaje;
}

void Personaje::setPuntaje(int value)
{
    puntaje = value;
}

int Personaje::getNivel() const
{
    return nivel;
}

void Personaje::setNivel(int value)
{
    nivel = value;
}

Personaje::Personaje()
{

}

Personaje::Personaje(float _px, float _py, float _vx, float _vy, float _ax)
{
    px=_px;
    py=_py;
    vx=_vx;
    vy=_vy;
    ax=_ax;
    setPos(px,py);
}


void Personaje::advance(int phase)
{
    vx = vx + ax*DT;
    vy = vy + ay*DT;

    px = px + vx*DT + 0.5*ax*DT*DT;
    py = py + vy*DT + 0.5*ay*DT*DT;
    setPos(px,py);
}



QRectF Personaje::boundingRect() const
{
    return QRectF(0,0,20,20);
}

void Personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->setBackground(Qt::magenta);
    painter->drawEllipse(boundingRect());
}

