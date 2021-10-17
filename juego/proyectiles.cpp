#include "proyectiles.h"


proyectiles::proyectiles()
{

}

proyectiles::proyectiles(float _px,float _py,float _vx,float _vy)
{
    px=_px;
    py=_py;
    vx=_vx;
    vy=_vy;


    setPos(px,py);

}

void proyectiles::advance(int phase)
{
    vx = vx + ax*DT;
    vy = vy + ay*DT;

    px = px + vx*DT + 0.5*ax*DT*DT;
    py = py + vy*DT + 0.5*ay*DT*DT;
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

