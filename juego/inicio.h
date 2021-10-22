#ifndef INICIO_H
#define INICIO_H

#include <QMainWindow>
#include "mainwindow.h"

namespace Ui {
class Inicio;
}

class Inicio : public QMainWindow
{
    Q_OBJECT

public:
    explicit Inicio(QWidget *parent = nullptr);
    ~Inicio();

private:
    Ui::Inicio *ui;
    MainWindow *juego;
};

#endif // INICIO_H
