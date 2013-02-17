#include "gameview.h"
#include "pecasView.h"
#include <QDebug>

gameView::gameView(Controller *controller):QGraphicsView()
{
    game = jogo::getInstance();
    game->attach(this);
    setController(controller);
    controller->addView(this);

    scene = new QGraphicsScene();
    scene->setSceneRect(0.0,0.0,600.0,600.0);
    this->setScene(scene);
}

void gameView::setController(Controller *ctr)
{
    controller = ctr;
}

void gameView::updateView(QString changeId)
{
    if(changeId == "Begin" || changeId == "Moved" || changeId == "Captura" || "BadMove")
    {
        updateTab(game->getTab());
    }
}

QPointF gameView::EventPosInicial()
{
}

QPointF gameView::EventPosFinal()
{
}

void gameView::updateTab(Tabuleiro *tab)
{
    scene->clear();
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(tab->GetDadosCasa(i,j)->GetCor()== true)
                scene->addRect(j*75,i*75,75,75,QPen(Qt::black),QBrush(Qt::white));
            else
                scene->addRect(j*75,i*75,75,75,QPen(Qt::black),QBrush(Qt::black));

            if(tab->GetDadosCasa(i,j)->GetPedra()!=NULL)
            {
                if(tab->GetDadosCasa(i,j)->GetPedra()->GetCor() == true)
                {
                    pecasView *elip = new pecasView(j,i,QBrush(Qt::white),controller);
                    scene->addItem(elip);
                }
                else
                {
                    pecasView *elip = new pecasView(j,i,QBrush(Qt::darkGray),controller);
                    scene->addItem(elip);
                }
            }
        }
    }
}

Controller *gameView::getController()
{
    return controller;
}
