#ifndef INICIO_H
#define INICIO_H

#include <QMainWindow>
#include "mainwindow.h"
#include <QPushButton>


namespace Ui {
class Inicio;
}

class Inicio : public QMainWindow
{
    Q_OBJECT

public:
    explicit Inicio(QWidget *parent = nullptr);
    ~Inicio();

    void startgame();
    void abrir();
    void closegame();
    void loadgame();
    void loadclose();

    void newgameclose();
    void newgame();
private slots:
    void on_loadbutton_clicked();

private:
    Ui::Inicio *ui;
    MainWindow *juego;
    QTimer *tiempo1;
    Personaje *efe;
    int vidas=3,level=1,score=0;


};

#endif // INICIO_H
