#include "coleccionables.h"

Coleccionables::Coleccionables()
{

}

Coleccionables::Coleccionables(float _px, float _py, int _tipo)
{
        px=_px;
        py=_py;
        tipo = _tipo;
        setPos(px,py);

}

QRectF Coleccionables::boundingRect() const
{
    return QRectF(0,0,20,20);
}

void Coleccionables::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRect j(0,0,20,20);
    QImage llaved("../imagenes/juego final/llaved.png");

    if(tipo==4){
        painter->drawImage(j,llaved);
    }
}
