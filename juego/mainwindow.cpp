#include "mainwindow.h"
#include "ui_mainwindow.h"
int i=0,f=0;
int inix,iniy;
int v,a,dis = 0;
bool multi;
bool ps = 0;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){}


MainWindow::MainWindow(QWidget *parent,int vidas,int level ,int score)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,0,0);
    ui->graphicsView->setScene(scene);
    ui->label->setVisible(false);
    ui->Back_Menu->setVisible(false);

    player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("../juego final/mario.mp3"));
    player->setVolume(50);
    player->play();


    QImage fondo("../imagenes/juego final/background4b.png");
    fondo.scaled(100,100);
    ui->graphicsView->setBackgroundBrush(fondo);



    tiempo = new QTimer();
    tiempo->start(10);

    connect(tiempo, &QTimer::timeout, this, &MainWindow::onUpdate);
    connect(tiempo, &QTimer::timeout, this, &MainWindow::onFire);
    connect(ui->Back_Menu,&QPushButton::clicked,this,&MainWindow::Menu);
    connect(ui->pause,&QPushButton::clicked,this,&MainWindow::pause);



    int x , y = 0;
    obtener_nivel(level);
    for(int i=0; i<20 ; i++){ //alto
        y=i*40;
        for(int j=0; j<60 ; j++){ //ancho
            x=j*40;

            if(nivel[i][j]!=0){
               if(nivel[i][j]==9){

                    pj1 = new Personaje(x,y,0,0,0,vidas,level,score);
                    //pj2 = new Personaje(x+40,y,0,0,0,3);
                    scene->addItem(pj1);
                    //scene->addItem(pj2);
                    scene->setSceneRect(pj1->getPx(),pj1->getPy(),0,0);
                    scene->foregroundBrush();
                    //scene->setSceneRect(pj2->getPx(),pj2->getPy(),0,0);
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
    ui->graphicsView->ensureVisible(pj1);
    ui->graphicsView->centerOn(pj1->getPx(),pj1->getPy());
    scene->setFocusItem(pj1);


//========================= colosiones Jugador 1============================================================================================

    QList<QGraphicsItem *> colisiones = scene->collidingItems(pj1); //bloques
    if(!colisiones.isEmpty())
    {
        objetos *muros = dynamic_cast<objetos *>(colisiones[0]);
        if(muros){
            for(int i=0;i<colisiones.size();i++)
            {
                //qDebug()<<"Lista"<<colisiones.size();
                objetos *muros2 = dynamic_cast<objetos *>(colisiones[i]);
                if(muros2->getTipo()==3 && pj1->getVidas()>=0)
                {
                    pj1->setPx(inix);
                    pj1->setPy(iniy);
                    pj1->setVidas(pj1->getVidas()-1);
                    qDebug()<<"Pinchos"<<pj1->getVidas();
                    //qDebug()<<"Pinchos"<<pj1->getPx()<<"vs"<<muros->getPx()<<"  "<<pj1->getPy()<<"vs"<<muros->getPy();
                if(pj1->getVidas()==0){scene->removeItem(pj1);}
                break;
                }

                else if(muros2->getTipo()==2){
                    pj1->setAy(0);
                    pj1->setVx(0);

                }


                else if(muros2->getTipo()==1 || muros2->getTipo()==5 || muros2->getTipo()==6)
                {
                                                    //izquierda
                    if( (pj1->getPx()+19>muros2->getPx()+40)&&(pj1->getPx() < (muros2->getPx()+40)) && (pj1->getPy() > muros2->getPy()) )
                    {
                        //qDebug()<<"Paso iz";
                        pj1->setVy(-0.1*pj1->getVy());
                        pj1->setAy(-0.1*pj1->getAy());
                        pj1->setVx(0);
                        pj1->setPx(pj1->getPx()+3);
                    }
                                                    //derecha
                    else if( (pj1->getPx()+19>muros2->getPx())&&(pj1->getPx() < muros2->getPx()) && (pj1->getPy() > muros2->getPy()) )
                    {
                        //qDebug()<<"Paso der";
                        pj1->setVy(-0.1*pj1->getVy());
                        pj1->setAy(-0.1*pj1->getAy());
                        pj1->setVx(0*pj1->getVx());
                        pj1->setPx(pj1->getPx()-3);
                    }

                    else if( (pj1->getPy() > muros2->getPy()) && (pj1->getPy() < muros2->getPy()+40) && (pj1->getPy()+18 > muros2->getPy()) && pj1->getVy() > 0 ){
                         qDebug()<<"Paso tec";
                        pj1->setPy(pj1->getPy()+5);
                        pj1->setVx(0);


                    }
                    else
                    {
                        if(muros2->getTipo()==5 || muros2->getTipo()==6){
                            if(muros2->getCont()==10){
                            pj1->setVx(i+muros2->getVx());}

                        }


                        if(muros2->getTipo()==6){
                            if(f==1){pj1->setVy(-20);}

                            else{pj1->setVy(muros2->getVy()-4);}
                        }


                        else{
                            pj1->setVy(-0.1*pj1->getVy());
                            pj1->setAy(-0.1*pj1->getAy());
                        }


                    }
                }
            }
        }
    }
    else{
        pj1->setAy(10);

    }

//=====================================================================================================================

//======================== colisones Jugador 2=============================================================================================

    /*QList<QGraphicsItem *> colisionesp2 = scene->collidingItems(pj2);
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
    }*/

//=====================================================================================================================

//============================ colosiones proyectiles ====================================================================

    copyammo = ammo;
    proyectiles *bu;
    for(list<proyectiles *>::iterator n=copyammo.begin();n!=copyammo.end();n++){
      bu= *n;
      QList<QGraphicsItem *> colisionesbala = scene->collidingItems(bu);
      if(!colisionesbala.isEmpty()){


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

                //qDebug()<<"Presione un tecla: "<<event->key();
                if(event->key() == Qt::Key_A){
                    pj1->setVx(-20);
                }else if(event->key() == Qt::Key_D){
                    pj1->setVx(20);
                }else if(event->key() == Qt::Key_W){
                   QList<QGraphicsItem *> colisiones = scene->collidingItems(pj1);
                    if(!colisiones.isEmpty()){

                        f=1;
                        pj1->setVy(-40);}
                 }
//=====================================================================================================================

//========================Controles Jugador 2==============================================================================

                //qDebug()<<"Presione un tecla: "<<event->key();
                if(event->key() == Qt::Key_J){
                    pj2->setVx(-20);
                }else if(event->key() == Qt::Key_L){
                    pj2->setVx(20);
                }else if(event->key() == Qt::Key_I){
                   QList<QGraphicsItem *> colisiones = scene->collidingItems(pj2);
                    if(!colisiones.isEmpty()){
                        objetos *muros = dynamic_cast<objetos *>(colisiones[0]);

                        if(muros->getTipo()==2){pj2->setVy(-10);}

                        else{pj2->setVy(-40);}
                    }
                }


//=====================================================================================================================
                if(event->key() == Qt::Key_P){
                   pause();

                }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event){

//===============================Control Jugador 1=====================================================================================

        //qDebug()<<"Presione un tecla: "<<event->key();
        if(event->key() == Qt::Key_A){
            pj1->setVx(0);
            i=0;
        }else if(event->key() == Qt::Key_D){
            pj1->setVx(0);
        }else if(event->key() == Qt::Key_W){
            f=0;
        }

//=====================================================================================================================

//===============================Control Jugador 2=======================================================================

        //qDebug()<<"Presione un tecla: "<<event->key();
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

void MainWindow:: Menu(){

    close();


}

void MainWindow::pause(){

    if(ps==0){
        tiempo->stop();ps=1;
        ui->label->setVisible(true);
        ui->Back_Menu->setVisible(true);
    }

    else{
        tiempo->start(10);ps=0;
        ui->label->setVisible(false);
        ui->Back_Menu->setVisible(false);
    }


}
