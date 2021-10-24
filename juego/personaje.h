#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <QGraphicsItem>
#include <QPainter>
#include <QDebug>

#define DT 0.05

class Personaje : public QGraphicsItem
{
private:
    int vidas;
    int puntaje;
    float px,py,vx,vy,ax;
    float ay = 10;
    int nivel;
    int llaves;
    int medallones;

public:
    Personaje();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    Personaje(float _px, float _py, float _vx, float _vy, float _ax,int _vidas, int _nivel, int _puntaje);
    void advance(int phase);
    int getVidas() const;
    void setVidas(int value);
    int getPuntaje() const;
    void setPuntaje(int value);
    int getNivel() const;
    void setNivel(int value);
    float getVx() const;
    void setVx(float value);
    float getVy() const;
    void setVy(float value);
    float getAy() const;
    void setAy(float value);
    float getPx() const;
    void setPx(float value);
    float getPy() const;
    void setPy(float value);
};


#endif // PERSONAJE_H
