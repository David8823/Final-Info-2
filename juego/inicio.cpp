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

    tiempo1 = new QTimer();
    tiempo1->start(1);

    loadclose();


    //ui->label->setStyleSheet("background-image:");

    connect(tiempo1, &QTimer::timeout, this, &Inicio::abrir);

    connect(ui->newpj,&QPushButton::clicked,this,&Inicio::on_newbutton_clicked);
    connect(ui->loadbutton,&QPushButton::clicked,this,&Inicio::on_loadbutton_clicked);

    connect(ui->newbutton,&QPushButton::clicked,this,&Inicio::newgame);
    connect(ui->continue_2,&QPushButton::clicked,this,&Inicio::loadgame);

    connect(ui->loadBack,&QPushButton::clicked,this,&Inicio::loadclose);
    connect(ui->exit,&QPushButton::clicked,this,&Inicio::closegame);



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
    QWidget *parent = nullptr;
    juego = new MainWindow(parent,vidas,level,score);
    juego->show();
    setVisible(false);
    ui->invalido->setVisible(false);
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

void Inicio::newgame(){

    ui->loadBack->setVisible(true);
    ui->Cuenta_2->setVisible(true);
    ui->incuenta->setVisible(true);
    ui->newpj->setVisible(true);
    ui->fondocon->setVisible(true);
    ui->invalido->setVisible(false);
}

void Inicio::loadgame(){

    ui->loadBack->setVisible(true);
    ui->Cuenta->setVisible(true);
    ui->incuenta->setVisible(true);
    ui->loadbutton->setVisible(true);
    ui->fondocon->setVisible(true);
    ui->invalido->setVisible(false);


}

void Inicio::loadclose(){
    ui->loadBack->setVisible(false);
    ui->Cuenta->setVisible(false);
    ui->incuenta->setVisible(false);
    ui->loadbutton->setVisible(false);
    ui->invalido->setVisible(false);
    ui->Cuenta_2->setVisible(false);
    ui->newpj->setVisible(false);
    ui->fondocon->setVisible(false);
}

void Inicio::on_loadbutton_clicked()
{
    ui->invalido->setVisible(false);
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
        vidas = vida;
        score = puntaje;
        level = nivel;
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


void Inicio::on_newbutton_clicked(){



}

