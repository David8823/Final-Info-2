#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QTimer>
#include <QKeyEvent>
#include <QDebug>
#include <list>
#include <fstream>
#include <string>

#include "objetos.h"
#include "proyectiles.h"
#include "personaje.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void onUpdate();
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void onFire();
    void obtener_nivel(int);
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene,*scene2;
    list<objetos *> muros;
    Personaje *pj1;
    Personaje *pj2;
    QTimer *tiempo;
    proyectiles *bala;
    list<objetos *> cannon;
    int nivel [10][20]={{0}};
    list<proyectiles *> ammo;
    list<proyectiles *> copyammo;
    QGraphicsView *v2;
    QMainWindow *w2;

};
#endif // MAINWINDOW_H
