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

proyectiles * objetos::generarbala(){

    bala = new proyectiles(0,0,0,0);

    return bala;
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
    QRect j(0,0,40,40);
    QImage puas("../imagenes/juego final/puas");
    QImage bloque("../imagenes/juego final/bloque");
    QImage arma("../imagenes/juego final/acofre");

    if (tipo == 8){
       painter->drawImage(j,arma);
   }else if(tipo == 1){
       painter->drawImage(j,bloque);
   }else if(tipo == 2){
       painter->setBrush(Qt::darkCyan);
   }else if(tipo == 3){
       painter->drawImage(j,puas);
   }

   painter->drawRect(boundingRect());
}
