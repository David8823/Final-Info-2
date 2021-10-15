#include "proyectiles.h"


proyectiles::proyectiles()
{

}

QRectF proyectiles::boundingRect() const
{
    return QRectF(40,40,35,35);
}

void proyectiles::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->setBrush(Qt::green);
    painter->drawEllipse(boundingRect());
}

