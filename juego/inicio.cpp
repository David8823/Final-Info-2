#include "inicio.h"
#include "ui_inicio.h"

bool cont = 0;

Inicio::Inicio(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Inicio)
{
    ui->setupUi(this);


    QImage fondo2("../juego final/fondoini.jpg");
    ui->graphicsView->setBackgroundBrush(fondo2);

    tiempo1 = new QTimer();
    tiempo1->start(1);

    loadclose();


    connect(ui->push1,&QPushButton::clicked,this,&Inicio::startgame);
    connect(tiempo1, &QTimer::timeout, this, &Inicio::abrir);
    connect(ui->exit,&QPushButton::clicked,this,&Inicio::closegame);
    connect(ui->continue_2,&QPushButton::clicked,this,&Inicio::loadgame);
    connect(ui->loadBack,&QPushButton::clicked,this,&Inicio::loadclose);

    juego = new MainWindow();





}

Inicio::~Inicio()
{
    delete ui;
}


void Inicio::startgame(){
    if(cont==1){

       delete juego;
    }
    juego = new MainWindow();
    juego->show();
    setVisible(false);
    cont = 1;

}

void Inicio::abrir(){
    if(juego->isHidden()){
            setVisible(true);
        }

}

void Inicio::closegame(){

    tiempo1->stop();
    close();

}

void Inicio::loadgame(){

    ui->loadBack->setVisible(true);
    ui->Cuenta->setVisible(true);
    ui->loadView->setVisible(true);
    ui->incuenta->setVisible(true);
    ui->loadbutton->setVisible(true);

}

void Inicio::loadclose(){
    ui->loadBack->setVisible(false);
    ui->Cuenta->setVisible(false);
    ui->loadView->setVisible(false);
    ui->incuenta->setVisible(false);
    ui->loadbutton->setVisible(false);
}
