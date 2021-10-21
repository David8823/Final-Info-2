#ifndef OBJETOS_H
#define OBJETOS_H
#include <QGraphicsItem>
#include <QPainter>
#include "proyectiles.h"
using namespace std;
#define DT 0.1

class objetos : public QGraphicsItem
{
private:
    int tipo;
    float px,py,vx,vy;
    proyectiles *bala;
public:
    objetos();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    objetos(float _px, float _py, int _tipo);
    void advance(int phase);
    int getTipo() const;
    void setTipo(int value);
    proyectiles * generarbala();
    float getPx() const;
    void setPx(float value);
    float getPy() const;
    void setPy(float value);
};

#endif // OBJETOS_H
