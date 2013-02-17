#include "mainwindow.h"
#include "pecasview.h"
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsGridLayout>
#include <QLayout>
#include <QSize>
#include "jogo.h"
#include <QString>
#include <QDebug>


MainWindow::MainWindow(Controller *controller, QWidget *parent)
    : QWidget(parent)
{
    setController(controller);
    game = jogo::getInstance();
    game->attach(this);

    this->setStyleSheet(" background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 black"
                        ",stop:.5 gray, stop: 1 white);");
    this->resize(900,650);

    player1 = new PontosView("Player1",controller);
    player2 = new PontosView("Player2",controller);

    inicia();
}

void MainWindow::inicia()
{
    iniciaView();
    iniciaLayout();
}

void MainWindow::iniciaView()
{
    view  = new gameView(controller);
    view->setFixedSize(600,600);
    view->setMaximumHeight(610);
    view->setMaximumWidth(610);
    view->setBackgroundBrush(QBrush(Qt::green));
    view->setFrameStyle(QFrame::Panel | QFrame::Raised);
    view->setLineWidth(1);
}

void MainWindow::iniciaLayout()
{
    layout = new QHBoxLayout();
    layout->addWidget(player1);
    layout->addWidget(view);
    layout->addWidget(player2);

    player2->setAlignment(Qt::AlignBottom);

    setLayout(layout);
}

MainWindow::~MainWindow()
{
    
}

void MainWindow::setController(Controller *ctr)
{
    controller = ctr;
}

Controller *MainWindow::getController()
{
}

void MainWindow::updateView(QString changeId)
{
    if(changeId == "Begin")
        show();
}

QPointF MainWindow::EventPosInicial()
{
}

QPointF MainWindow::EventPosFinal()
{
}
