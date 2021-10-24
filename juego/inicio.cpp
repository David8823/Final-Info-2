#include "inicio.h"
#include "ui_inicio.h"

#include <fstream>
#include <QString>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <QDebug>
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
    ui->invalido->setVisible(false);
}

void Inicio::on_loadbutton_clicked()
{
    ifstream datos;
    ofstream _datos;
    QString nombre=ui->incuenta->text();//,nivel,puntaje;
    string _nombre="../partidas/"+nombre.toStdString()+".txt",dato="";
    int puntaje=0, nivel=0, vida=0, cont=0;
    char* pEnd;
    //string _nivel, _puntaje;
    datos.open(_nombre);
    if(datos.is_open())
    {
        qDebug()<<"el usuario ya existe"<<endl;
        ui->incuenta->clear();
        while(!datos.eof())
            {
                getline(datos,dato);
                if(dato[0]=='/')
                {
                    cont = cont + 1;
                }
                else if(cont==1)
                {
                    nivel=strtod(dato.c_str(),&pEnd);
                }
                else if(cont==2)
                {
                    puntaje=strtod(dato.c_str(),&pEnd);
                }
                else if(cont==3)
                {
                    vida=strtod(dato.c_str(),&pEnd);
                }
                dato="";
            }
            datos.close();
        efe = new Personaje(0,0,0,0,0,vida,nivel,puntaje);
        startgame();
        loadclose();
    }
    else
    {
        /*_datos.open(_nombre);
        nivel=ui->nivel->text();
        puntaje=ui->puntos->text();
        _nivel=nivel.toStdString();
        _datos<<_nivel<<"\n/\n";
        _puntaje=puntaje.toStdString();
        _datos<<_puntaje;*/
        ui->invalido->setVisible(true);
    }
}
