#ifndef PROYECTILES_H
#define PROYECTILES_H
#include <QGraphicsItem>
#include <QPainter>

class proyectiles : public QGraphicsItem
{
private:
    float px,py,vx,vy,ax,ay;
    int tipo,time;

public:
    proyectiles();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // PROYECTILES_H
