#ifndef PROYECTILES_H
#define PROYECTILES_H
#include <QGraphicsItem>
#include <QPainter>
#define DT 0.05

class proyectiles : public QGraphicsItem
{
private:
    float px,py,pxini,pyini,vx,vy,vyini,dt;
    float ay = 10;
    int tipo,time=400;


public:
    proyectiles();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void advance(int phase);
    proyectiles(float _px, float _py, float vx, float vy,int tipo);
    int getTime() const;
    void setTime(int value);
    int getTipo() const;
    void setTipo(int value);
};

#endif // PROYECTILES_H
