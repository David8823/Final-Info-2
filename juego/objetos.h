#ifndef OBJETOS_H
#define OBJETOS_H
#include <QGraphicsItem>
#include <QPainter>

#define DT 0.1

class objetos : public QGraphicsItem
{
private:
    int tipo;
    float px,py,vx,vy;


public:
    objetos();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    objetos(float _px, float _py, int _tipo);
    void advance(int phase);
    int getTipo() const;
    void setTipo(int value);
};

#endif // OBJETOS_H
