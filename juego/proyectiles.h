#ifndef PROYECTILES_H
#define PROYECTILES_H
#include <QGraphicsItem>
#include <QPainter>
#define DT 0.01

class proyectiles : public QGraphicsItem
{
private:
    float px,py,vx,vy,ax;
    float ay = 0;
    int tipo,time;

public:
    proyectiles();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void advance(int phase);
    proyectiles(float _px, float _py, float vx, float vy);
};

#endif // PROYECTILES_H
