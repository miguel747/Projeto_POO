#include "mainwindow.h"
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsGridLayout>
#include <QLayout>
#include <QSize>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    this->setStyleSheet(" background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 black"
                        ",stop:.5 gray, stop: 1 white);");
    this->resize(900,650);

    scene = new QGraphicsScene(0,0,600,600);
    view  = new QGraphicsView();
    view->setScene(scene);
    view->setBackgroundBrush(QBrush(Qt::green));
    view->setMaximumHeight(610);
    view->setMaximumWidth(610);

    layout = new QHBoxLayout();




    iniciaLabel();
    iniciaTabView(":/Casas/Branca",":/Casas/Preta");
    iniciaPecaView();


    view->setFrameStyle(QFrame::Panel | QFrame::Raised);
    view->setLineWidth(1);

    layout->addWidget(player1);
    layout->addWidget(view);
    layout->addWidget(player2);


    setLayout(layout);
}



MainWindow::~MainWindow()
{
    
}
void MainWindow::iniciaTabView(QString imCasaBranca, QString imCasaPreta)
{
    int linha,i,j;
    for(i = 0;i<8;i++){
        linha = (i*j/8)%2;
        for(j = 0; j<8;j++){
            if(linha==0){
                if(j%2==0){
                    scene->addRect(i*75,j*75,75,75,QPen(Qt::black),QBrush(QImage(imCasaBranca)));
                    scene->itemAt(i*75,j*75)->setZValue(-1);
                }
                else{
                    scene->addRect(i*75,j*75,75,75,QPen(Qt::black),QBrush(QImage(imCasaPreta)));
                    scene->itemAt(i*75,j*75)->setZValue(-1);
                }
            }
            else{
                if(j%2==0){
                    scene->addRect(i*75,j*75,75,75,QPen(Qt::black),QBrush(QImage(imCasaPreta)));
                    scene->itemAt(i*75,j*75)->setZValue(-1);
                }
                else{
                    scene->addRect(i*75,j*75,75,75,QPen(Qt::black),QBrush(QImage(imCasaBranca)));
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
            if(i==0||i==2){
                if(j%2==1){
                    QGraphicsEllipseItem *elip = new QGraphicsEllipseItem(i*75,j*75,70,70);
                    scene->addItem(elip);
                    elip->setZValue(3);
                    elip->setBrush(QBrush(Qt::white));
                    scene->itemAt(i*75+75.0/2.0,j*75+75.0/2.0)->setFlags(QGraphicsItem::ItemIsMovable);
                }
            }
            else
                if(j%2==0){
                    QGraphicsEllipseItem *elip = new QGraphicsEllipseItem(i*75,j*75,70,70);
                    scene->addItem(elip);
                    elip->setZValue(3);
                    elip->setBrush(QBrush(Qt::white));
                    scene->itemAt(i*75+75.0/2.0,j*75+75.0/2.0)->setFlags(QGraphicsItem::ItemIsMovable);
                }
        }


    }

    for(i = 5;i<8;i++){
        for(j = 0; j<8;j++){
            if(i==5||i==7){
                if(j%2==0){
                    QGraphicsEllipseItem *elip = new QGraphicsEllipseItem(i*75,j*75,70,70);
                    scene->addItem(elip);
                    elip->setZValue(3);
                    elip->setBrush(QBrush(Qt::blue));
                    scene->itemAt(i*75+75.0/2.0,j*75+75.0/2.0)->setFlags(QGraphicsItem::ItemIsMovable);
                }
            }
            else
                if(j%2==1){
                    QGraphicsEllipseItem *elip = new QGraphicsEllipseItem(i*75,j*75,70,70);
                    scene->addItem(elip);
                    elip->setZValue(3);
                    elip->setBrush(QBrush(Qt::blue));
                    scene->itemAt(i*75+75.0/2.0,j*75+75.0/2.0)->setFlags(QGraphicsItem::ItemIsMovable);
                }
        }
    }
}

void MainWindow::iniciaLabel()
{
    player1 = new QLabel("Player1-->");
    player1->setStyleSheet("color: white; font-size: 15px;");
    player1->setFrameStyle(QFrame::Panel | QFrame::Raised);
    player1->setLineWidth(4);
    player2 = new QLabel("<--Player2");
    player2->setStyleSheet("color: white; font-size: 15px");
    player2->setFrameStyle(QFrame::Panel | QFrame::Raised);
    player2->setLineWidth(4);
}
