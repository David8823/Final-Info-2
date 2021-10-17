#include "mainwindow.h"
#include "ui_mainwindow.h"

int inix,iniy;
int v,a,dis = 0;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,0,0);
    ui->graphicsView->setScene(scene);
    QImage fondo("../imagenes/juego final/fondo");

    ui->graphicsView->setBackgroundBrush(fondo);


    tiempo = new QTimer();
    tiempo->start(20);

    connect(tiempo, &QTimer::timeout, this, &MainWindow::onUpdate);
    connect(tiempo, &QTimer::timeout, this, &MainWindow::onFire);

    int x , y = 0, num_nivel=2;
    obtener_nivel(num_nivel);
    for(int i=0; i<10 ; i++){
        y=i*40;
        for(int j=0; j<20 ; j++){
            x=j*40;

            if(nivel[i][j]!=0){
               if(nivel[i][j]==9){

                    pj1 = new Personaje(x,y,0,0,0,3);
                    scene->addItem(pj1);
                    scene->setSceneRect(pj1->getPx(),pj1->getPy(),0,0);
                    ui->graphicsView->setScene(scene);
                    inix = x;
                    iniy = y;


               }
               else if(nivel[i][j]==8){
                    cannon.push_back(new objetos(x,y,nivel[i][j]));
                    scene->addItem(cannon.back());
               }


               else{
                    muros.push_back(new objetos(x,y,nivel[i][j]));
                    scene->addItem(muros.back());
               }
            }
        }

    }
    scene->setSceneRect(pj1->getPx(),pj1->getPy(),0,0);
    ui->graphicsView->setScene(scene);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onUpdate(){
    scene->advance();

    QList<QGraphicsItem *> colisiones = scene->collidingItems(pj1);
    if(!colisiones.isEmpty()){
        objetos *item = dynamic_cast<objetos *>(colisiones[0]);
        if(item)
            if(item->getTipo()==4){
            item->setTipo(3);}

        objetos *muros = dynamic_cast<objetos *>(colisiones[0]);
        if(muros){
            if(muros->getTipo()==4){
                muros->setTipo(3);
                pj1->setVx(0);
                pj1->setVy(0);}

            else if(muros->getTipo()==3 || muros->getTipo()==0){
                pj1->setPx(inix);
                pj1->setPy(iniy);
                pj1->setVidas(pj1->getVidas()-1);


                if(pj1->getVidas()==0){scene->removeItem(pj1);}
            }

            else if(muros->getTipo()==1 || muros->getTipo()==2){

                pj1->setVy(-0.1*pj1->getVy());
                pj1->setAy(-0.1*pj1->getAy());

            }
        }
    }
    else{
        pj1->setAy(9.8);

    }

}

void MainWindow::keyPressEvent(QKeyEvent *event)
{

                qDebug()<<"Presione un tecla: "<<event->key();
                if(event->key() == Qt::Key_A){
                    pj1->setVx(-20);
                }else if(event->key() == Qt::Key_D){
                    pj1->setVx(20);
                }else if(event->key() == Qt::Key_W){
                   QList<QGraphicsItem *> colisiones = scene->collidingItems(pj1);
                    if(!colisiones.isEmpty()){

                       pj1->setVy(-40);}
                 }



}

void MainWindow::keyReleaseEvent(QKeyEvent *event){


        qDebug()<<"Presione un tecla: "<<event->key();
        if(event->key() == Qt::Key_A){
            pj1->setVx(0);
        }else if(event->key() == Qt::Key_D){
            pj1->setVx(0);
        }


}

void MainWindow::onFire(){
    objetos *p;
    if(dis==250){

        for(list<objetos *>::iterator n=cannon.begin();n!=cannon.end();n++){
            p= *n;
            bala = p->generarbala();

            scene->addItem(bala);
            dis = 0;
        }
    }
    else{dis++;}
}

void MainWindow:: obtener_nivel(int num_nivel)
{
    int cont=0,fila=0,largo=0;
    ifstream sis;
    string datos="";
    sis.open("../niveles.txt");
    while(!sis.eof())
    {
        getline(sis,datos);
        if(datos[0]=='/')
        {
            cont = cont + 1;
            if(cont>num_nivel)
            {
                break;
            }
        }
        if(cont==num_nivel && datos[0]!='/')
        {
            largo=datos.size();
            for(int columna=0,i=0;i<=largo;columna++)
            {
                nivel[fila][columna]=datos[i]-'0';
                i=i+2;
            }
            fila = fila + 1;
        }
        datos="";
    }
    sis.close();
}
