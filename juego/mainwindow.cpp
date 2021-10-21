#include "mainwindow.h"
#include "ui_mainwindow.h"

int inix,iniy;
int v,a,dis = 0;
bool multi;
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
    tiempo->start(1);

    connect(tiempo, &QTimer::timeout, this, &MainWindow::onUpdate);
    connect(tiempo, &QTimer::timeout, this, &MainWindow::onFire);

    int x , y = 0, num_nivel=1;
    obtener_nivel(num_nivel);
    for(int i=0; i<10 ; i++){
        y=i*40;
        for(int j=0; j<20 ; j++){
            x=j*40;

            if(nivel[i][j]!=0){
               if(nivel[i][j]==9){

                    pj1 = new Personaje(x,y,0,0,0,3);
                    pj2 = new Personaje(x+40,y,0,0,0,3);
                    scene->addItem(pj1);
                    scene->addItem(pj2);
                    scene->setSceneRect(pj1->getPx(),pj1->getPy(),0,0);
                    scene->setSceneRect(pj2->getPx(),pj2->getPy(),0,0);
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


    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->centerOn(pj1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onUpdate(){
    scene->advance();

//========================= colosiones Jugador 1============================================================================================

    QList<QGraphicsItem *> colisiones = scene->collidingItems(pj1); //bloques
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
        pj1->setAy(10);
    }


   /* QList<QGraphicsItem *> colisiones2 = scene->collidingItems(pj1); //proyectiles
    if(!colisiones2.isEmpty()){
        proyectiles *item = dynamic_cast<proyectiles *>(colisiones2[0]);
        if(item)
            if(item->getTipo()==4){
            item->setTipo(3);}

        proyectiles *ammos = dynamic_cast<proyectiles *>(colisiones2[0]);
        if(ammos){
            if(ammos->getTipo()==1){
                ammos->setTipo(3);
                pj1->setVx(0);
                pj1->setVy(0);}

            else if(ammos->getTipo()==3){
                pj1->setPx(inix);
                pj1->setPy(iniy);
                pj1->setVidas(pj1->getVidas()-1);
                scene->removeItem(ammos);
                for(list<proyectiles *>::iterator non=ammo.begin();non!=ammo.end();non++){
                    if(ammos==*non ){ammo.remove(*non);break;}
                }

                if(pj1->getVidas()==0){scene->removeItem(pj1);}
            }

            else if(ammos->getTipo()==2){

                pj1->setVy(-0.1*pj1->getVy());
                pj1->setAy(-0.1*pj1->getAy());

            }
        }
    }*/

//=====================================================================================================================

//======================== colisones Jugador 2=============================================================================================

    QList<QGraphicsItem *> colisionesp2 = scene->collidingItems(pj2);
    if(!colisionesp2.isEmpty()){
        objetos *item = dynamic_cast<objetos *>(colisionesp2[0]);
        if(item)
            if(item->getTipo()==4){
            item->setTipo(3);}

        objetos *muros = dynamic_cast<objetos *>(colisionesp2[0]);
        if(muros){
            if(muros->getTipo()==4){
                muros->setTipo(3);
                pj2->setVx(0);
                pj2->setVy(0);}

            else if(muros->getTipo()==3 || muros->getTipo()==0){
                pj2->setPx(inix);
                pj2->setPy(iniy);
                pj2->setVidas(pj2->getVidas()-1);


                if(pj2->getVidas()==0){scene->removeItem(pj2);}
            }

            else if(muros->getTipo()==1 || muros->getTipo()==2){

                pj2->setVy(-0.1*pj2->getVy());
                pj2->setAy(-0.1*pj2->getAy());

            }
        }

        else{
            Personaje *personajes = dynamic_cast<Personaje *>(colisionesp2[0]);
            if(personajes){

                pj2->setVy(-0.1*pj2->getVy());
                pj2->setAy(-0.1*pj2->getAy());


            }
        }

    }
    else{
        pj2->setAy(10);
    }

//=====================================================================================================================

//============================ colosiones proyectiles ====================================================================

    copyammo = ammo;
    proyectiles *bu;
    for(list<proyectiles *>::iterator n=copyammo.begin();n!=copyammo.end();n++){
      bu= *n;
      QList<QGraphicsItem *> colisionesbala = scene->collidingItems(bu);
      if(!colisionesbala.isEmpty()){
          objetos *item = dynamic_cast<objetos *>(colisionesbala[0]);
          if(item)
              if(item->getTipo()==4){
              item->setTipo(3);}

          objetos *muros = dynamic_cast<objetos *>(colisionesbala[0]);
          if(muros){
              if(muros->getTipo()==1){
                  scene->removeItem(bu);
                  for(list<proyectiles *>::iterator non=ammo.begin();non!=ammo.end();non++){
                      if(bu==*non ){ammo.remove(*non);break;}
                  }

              }

              else{

              }
          }

          else{
              Personaje *personajes = dynamic_cast<Personaje *>(colisionesbala[0]);
              if(personajes){
                  scene->removeItem(bu);
                  personajes->setPx(inix);
                  personajes->setPy(iniy);
                  personajes->setVidas(personajes->getVidas()-1);

                  for(list<proyectiles *>::iterator non=ammo.begin();non!=ammo.end();non++){
                      if(bu==*non ){ammo.remove(*non);break;}
                  }

                  if(personajes->getVidas()==0){scene->removeItem(personajes);}


              }

          }

      }
    }
//=====================================================================================================================



}

void MainWindow::keyPressEvent(QKeyEvent *event)
{

//========================Controles Jugador 1==============================================================================
                bool go=1;
                qDebug()<<"Presione un tecla: "<<event->key();
                if(event->key() == Qt::Key_A){
                    pj1->setVx(-20);
                    /*QList<QGraphicsItem *> colisionesp2 = scene->collidingItems(pj1);
                    if(!colisionesp2.isEmpty()){

                        objetos *muros = dynamic_cast<objetos *>(colisionesp2[0]);

                        for(int i=0; i < colisionesp2.size() ;i++){

                            objetos *muros = dynamic_cast<objetos *>(colisionesp2[i]);
                            qDebug()<<"Presione un tecla: "<<pj1->getPx()<<"vs"<<muros->getPx()<<"  "<<pj1->getPy()<<"vs"<<muros->getPy();
                            if(muros->getTipo()==1 && pj1->getPx() < muros->getPx()+40 && pj1->getPy()+18 > muros->getPy()) {
                                go=0;
                                qDebug()<<"Paso";
                                break;
                            }

                        }


                            if(go==0) {

                                pj2->setVx(0);
                                pj2->setVy(0);}

                            else{pj1->setVx(-20);}


                    }

                    else{pj1->setVx(-20);}

                */
                }
                else if(event->key() == Qt::Key_D){
                    pj1->setVx(20);
                }else if(event->key() == Qt::Key_W){
                   QList<QGraphicsItem *> colisiones = scene->collidingItems(pj1);
                    if(!colisiones.isEmpty()){

                       pj1->setVy(-40);}
                 }
//=====================================================================================================================

//========================Controles Jugador 2==============================================================================

                qDebug()<<"Presione un tecla: "<<event->key();
                if(event->key() == Qt::Key_J){
                    pj2->setVx(-20);
                }else if(event->key() == Qt::Key_L){
                    pj2->setVx(20);
                }else if(event->key() == Qt::Key_I){
                   QList<QGraphicsItem *> colisiones = scene->collidingItems(pj2);
                    if(!colisiones.isEmpty()){

                       pj2->setVy(-40);}
                 }
//=====================================================================================================================

}

void MainWindow::keyReleaseEvent(QKeyEvent *event){

//===============================Control Jugador 1=====================================================================================

        qDebug()<<"Presione un tecla: "<<event->key();
        if(event->key() == Qt::Key_A){
            pj1->setVx(0);
        }else if(event->key() == Qt::Key_D){
            pj1->setVx(0);
        }

//=====================================================================================================================

//===============================Control Jugador 2=======================================================================

        qDebug()<<"Presione un tecla: "<<event->key();
        if(event->key() == Qt::Key_J){
            pj2->setVx(0);
        }else if(event->key() == Qt::Key_L){
            pj2->setVx(0);
        }

//=====================================================================================================================

}

void MainWindow::onFire(){
    objetos *p;
    if(dis==250){

        for(list<objetos *>::iterator n=cannon.begin();n!=cannon.end();n++){
            p= *n;
            bala = p->generarbala();
            ammo.push_back(bala);
            scene->addItem(ammo.back());
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
