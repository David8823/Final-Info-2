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
private:
    Ui::Inicio *ui;
    MainWindow *juego;
    QTimer *tiempo1;

};

#endif // INICIO_H
