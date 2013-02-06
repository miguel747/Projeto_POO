#include "mainwindow.h"
#include "pecasview.h"
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsGridLayout>
#include <QLayout>
#include <QSize>
#include <QDebug>
#include "Tabuleiro.h"
#include <QString>


MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    this->setStyleSheet(" background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 black"
                        ",stop:.5 gray, stop: 1 white);");
    this->resize(900,650);

    inicia();

}

void MainWindow::inicia()
{
    iniciaScene();
    iniciaView();
    iniciaLabel();
    iniciaTabView(":/Casas/Branca",":/Casas/Preta");
    iniciaPecaView();
    iniciaLayout();
}

void MainWindow::iniciaView()
{
    view  = new QGraphicsView();
    view->setFixedSize(600,600);
    view->setMaximumHeight(610);
    view->setMaximumWidth(610);
    view->setScene(scene);
    view->setBackgroundBrush(QBrush(Qt::green));
    view->setFrameStyle(QFrame::Panel | QFrame::Raised);
    view->setLineWidth(1);
}

void MainWindow::iniciaScene()
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0.0,0.0,600.0,600.0);
}

void MainWindow::iniciaLayout()
{
    layout = new QHBoxLayout();
    layout->addWidget(player1);
    layout->addWidget(view);
    layout->addWidget(player2);

    setLayout(layout);
}

MainWindow::~MainWindow()
{
    
}

//void updateview(Tabuleiro tab)
//{
//    for(int i = 0; i<8 ; i++){
//        for(int j = 0; j<8 ; j++)
//        {
//           //tab.GetDadosCasa()
//        }
//    }
//}

void MainWindow::iniciaTabView(QString imCasaBranca, QString imCasaPreta)
{
    int linha,i,j;

    for(i = 0;i<8;i++){
        linha = (i*j/8)%2;                                                      //linha = 0 se linha par, 1 caso contrario
        for(j = 0; j<8;j++){
            if(linha==0){                                                       // linha == 0 ?
                if(j%2==0){                                                     // sim colunas pares sao pretas
                    scene->addRect(i*75,j*75,75,75,QPen(Qt::black),
                                   QBrush(QImage(imCasaBranca)));
                    scene->itemAt(i*75,j*75)->setZValue(-1);
                }
                else{
                    scene->addRect(i*75,j*75,75,75,QPen(Qt::black),
                                   QBrush(QImage(imCasaPreta)));
                    scene->itemAt(i*75,j*75)->setZValue(-1);
                }
            }
            else{                                                               // Nao colunas pares sao brancas
                if(j%2==0){
                    scene->addRect(i*75,j*75,75,75,QPen(Qt::black),
                                   QBrush(QImage(imCasaPreta)));
                    scene->itemAt(i*75,j*75)->setZValue(-1);
                }
                else{
                    scene->addRect(i*75,j*75,75,75,QPen(Qt::black),
                                   QBrush(QImage(imCasaBranca)));
                    scene->itemAt(i*75,j*75)->setZValue(-1);
                }
            }


        }
    }

}

void MainWindow::iniciaPecaView()
{
    int i,j;
    for(i = 0;i<3;i++){
        for(j = 0; j<8;j++){
            if(i==0||i==2){                                                     // Linha par ?
                if(j%2==1){                                                     // Sim. j eh impar ?
                    pecasView *elip = new pecasView(i,j,QBrush(Qt::white));
                    scene->addItem(elip);
                }
            }
            else                                                                // Nao
                if(j%2==0){                                                     // j eh par ?
                    pecasView *elip = new pecasView(i,j,QBrush(Qt::white));
                    scene->addItem(elip);
                }
        }


    }

    for(i = 5;i<8;i++){
        for(j = 0; j<8;j++){
            if(i==5||i==7){                                                     // Linha par ?
                if(j%2==0){                                                     // Sim. j eh par ?
                    pecasView *elip = new pecasView(i,j,QBrush(Qt::black));
                    scene->addItem(elip);
                }
            }
            else                                                                // Nao
                if(j%2==1){                                                     // j eh impar ?
                    pecasView *elip = new pecasView(i,j,QBrush(Qt::black));
                    qDebug()<<elip->pos();
                    scene->addItem(elip);
                    qDebug()<<scene->itemAt(elip->pos());
                    //qDebug()<<elip;
                }
        }
    }
}

void MainWindow::iniciaLabel()
{
    player1 = new QLabel("<--Player1");
    player1->setStyleSheet("color: white; font-size: 15px");
    player1->setFrameStyle(QFrame::Panel | QFrame::Raised);
    player1->setLineWidth(4);

    player2 = new QLabel("<--Player1");
    player2->setStyleSheet("color: white; font-size: 15px");
    player2->setFrameStyle(QFrame::Panel | QFrame::Raised);
    player2->setLineWidth(4);
    player2->setAlignment(Qt::AlignBottom);


}
