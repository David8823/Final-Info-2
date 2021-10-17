#include "proyectiles.h"


int proyectiles::getTime() const
{
    return time;
}

void proyectiles::setTime(int value)
{
    time = value;
}

proyectiles::proyectiles()
{

}

proyectiles::proyectiles(float _px,float _py,float _vx,float _vy)
{
    pxini=_px;
    pyini=_py;
    vx=_vx;
    vyini=_vy;
    dt=0;

    setPos(pxini,pyini);

}

void proyectiles::advance(int phase)
{
    vy = vyini + ay*dt;

    px = pxini + vx*dt;
    py = pyini + vy*dt + 0.5*ay*dt*dt;

    dt=dt+DT/10;
    time=time-20;
    setPos(px,py);
}


QRectF proyectiles::boundingRect() const
{
    return QRectF(0,0,20,20);
}

void proyectiles::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->setBrush(Qt::green);
    painter->drawEllipse(boundingRect());
}

