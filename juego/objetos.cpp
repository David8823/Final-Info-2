#include "objetos.h"


int objetos::getTipo() const
{
    return tipo;
}

void objetos::setTipo(int value)
{
    tipo = value;
}

float objetos::getPx() const
{
    return px;
}

void objetos::setPx(float value)
{
    px = value;
}

float objetos::getPy() const
{
    return py;
}

void objetos::setPy(float value)
{
    py = value;
}

float objetos::getVx() const
{
    return vx;
}

void objetos::setVx(float value)
{
    vx = value;
}

objetos::objetos()
{

}

proyectiles * objetos::generarbala(){

    bala = new proyectiles(px,py,50,-100,3);
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
        pxini= _px;
        pyini=_py;
        setPos(px,py);

}

void objetos::advance(int phase)
{
    if(tipo==5)
    {
        if(cont==150){
            vx=-vx;
            cont=0;
        }

        else{
            px = px + vx*DT;
            cont++;
            setPos(px,py);
        }
    }

    else if(tipo==4){


        float theta0 = theta * cos(w*DT);
        px =pxini + 1 * sin(theta0*rad);
        py =pyini - 1 * cos(theta0*rad);
        setPos(px,py);

    }

    else if(tipo==4){


        float theta0 = theta * cos(w*DT);
        px =pxini + 1 * sin(theta0*rad);
        py =pyini - 1 * cos(theta0*rad);
        setPos(px,py);
    }

}


void objetos::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRect j(0,0,40,40);
    QImage puas("../juego final/puas.png");
    QImage bloque("../juego final/bloque.png");
    QImage arma("../juego final/acofre.png");

    if (tipo == 8){
       painter->drawImage(j,arma);
   }else if(tipo == 1 || tipo==5){
       painter->drawImage(j,bloque);
   }else if(tipo == 2){
       painter->setBrush(Qt::darkCyan);
   }else if(tipo == 3){
       painter->drawImage(j,puas);
   }else if(tipo == 4){
    painter->drawImage(j,puas);
    }

}
