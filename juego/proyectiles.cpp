 #include "proyectiles.h"


int proyectiles::getTime() const
{
    return time;
}

void proyectiles::setTime(int value)
{
    time = value;
}

int proyectiles::getTipo() const
{
    return tipo;
}

void proyectiles::setTipo(int value)
{
    tipo = value;
}

proyectiles::proyectiles()
{

}

proyectiles::proyectiles(float _px,float _py,float _vx,float _vy,int _tipo)
{
    pxini=_px;
    pyini=_py;
    vx=_vx;
    vyini=_vy;
    dt=0;
    tipo=_tipo;

    setPos(pxini,pyini);

}

void proyectiles::advance(int phase)
{
    vy = vyini + ay*dt;

    px = pxini + vx*dt;
    py = pyini + vy*dt + 0.5*ay*dt*dt;

    dt=dt+DT/2;
    time=time-20;
    setPos(px,py);
}


QRectF proyectiles::boundingRect() const
{
    return QRectF(0,0,20,20);
}

void proyectiles::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    QImage bullet("../imagenes/juego final/bullet");

    painter->setBrush(bullet);
    //painter->setBrush(Qt::green);
    painter->drawEllipse(boundingRect());
}

