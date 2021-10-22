#include "inicio.h"
#include "ui_inicio.h"

Inicio::Inicio(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Inicio)
{
    ui->setupUi(this);

    juego = new MainWindow();
    juego->show();

}

Inicio::~Inicio()
{
    delete ui;
}
