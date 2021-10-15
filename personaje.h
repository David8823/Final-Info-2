#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <QGraphicsItem>
#include <QPainter>
#include <QDebug>

#define DT 0.1

class Personaje : public QGraphicsItem
{
private:
    int vidas;
    int puntaje;
    float px,py,vx,vy,ax;
    float const ay = 10;
    int nivel;
    int llaves;
    int medallones;

public:
    Personaje();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    Personaje(float _px, float _py, float _vx, float _vy, float _ax);
    void advance(int phase);
    int getVidas() const;
    void setVidas(int value);
    int getPuntaje() const;
    void setPuntaje(int value);
    int getNivel() const;
    void setNivel(int value);
};


#endif // PERSONAJE_H
