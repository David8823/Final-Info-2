#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,0,0);
    ui->graphicsView->setScene(scene);

    tiempo = new QTimer();

    int x , y = 0;

    for(int i=0; i<10 ; i++){
        y=i*40;
        for(int j=0; j<20 ; j++){
            x=j*40;

            if(nivel1[i][j]!=0){
               if(nivel1[i][j]==9){

                    pj1 = new Personaje(x,y,0,0,0);
                    scene->addItem(pj1);

               }
                else{
                    muros.push_back(new objetos(x,y,nivel1[i][j]));
                    scene->addItem(muros.back());
               }
            }


        }

    }


}

MainWindow::~MainWindow()
{
    delete ui;
}

