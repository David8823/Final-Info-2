#ifndef INICIO_H
#define INICIO_H

#include <QMainWindow>
#include "mainwindow.h"
//#include "personaje.h"
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
private slots:
    void on_loadbutton_clicked();

private:
    Ui::Inicio *ui;
    MainWindow *juego;
    QTimer *tiempo1;
    Personaje *efe;

};

#endif // INICIO_H
