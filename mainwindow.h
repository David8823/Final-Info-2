#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsItem>
#include <QTimer>
#include <QKeyEvent>
#include <QDebug>
#include <QVector>

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

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    list<objetos *> muros;
    Personaje *pj1;
    QTimer *tiempo;

    int nivel1 [10][20] ={
                      {0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,2,2,2,2,0},
                      {0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0},
                      {0,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
                      {0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,1},
                      {0,9,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,1},
                      {1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,0,1,1,1,1}
                      };

    int nivel2 [10][20] ={
                      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                      {1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
                      };
};
#endif // MAINWINDOW_H
