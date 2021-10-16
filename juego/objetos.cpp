#include "objetos.h"


int objetos::getTipo() const
{
    return tipo;
}

void objetos::setTipo(int value)
{
    tipo = value;
}

objetos::objetos()
{

}

QRectF objetos::boundingRect() const
{
    return QRectF(0,0,40,40);
}

objetos::objetos(float _px, float _py, int _tipo)
{
        px=_px;
        py=_py;
        tipo = _tipo;
        setPos(px,py);
}

void objetos::advance(int phase)
{
    if(tipo==99)
    {
    px = px + vx*DT;
    py = py + vy*DT;
    setPos(px,py);
    }

}


void objetos::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (tipo == 4){
       painter->setBrush(Qt::yellow);
   }else if(tipo == 1){
       painter->setBrush(Qt::magenta);
   }else if(tipo == 2){
       painter->setBrush(Qt::red);
   }else if(tipo == 3){
       painter->setBrush(Qt::blue);
   }

   painter->drawRect(boundingRect());
}
