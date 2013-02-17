#include "pontosview.h"
#include <QDebug>

PontosView::PontosView(QString Player, Controller *ctr, QWidget *parent) :
    QLabel(parent)
{
    game = jogo::getInstance();
    controller = ctr;
    controller->addView(this);

    game->attach(this);


    setText("Player-->");
    setStyleSheet("color: white; font-size: 15px");
    setFrameStyle(QFrame::Panel | QFrame::Raised);
    setLineWidth(4);
}

void PontosView::setController(Controller *)
{
}

Controller *PontosView::getController()
{
}

void PontosView::updateView(QString changeId)
{
    if(changeId == "Begin" || changeId == "Captura")
    {
        //jogo.getPontos(Player)
    }
}

QPointF PontosView::EventPosInicial()
{
}

QPointF PontosView::EventPosFinal()
{
}
