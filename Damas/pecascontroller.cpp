#include "pecascontroller.h"
#include "jogo.h"
#include <QDebug>

pecasController::pecasController()
{
    newGame = jogo::getInstance();
}

void pecasController::setView(iView *newView)
{
    this->view = newView;
}

iView *pecasController::getView()
{
    return view;
}

void pecasController::setModel(jogo *newGame)
{
    this->newGame = newGame;
}

jogo *pecasController::getModel()
{
    return newGame;
}

void pecasController::inicia()
{
    setModel(jogo::getInstance());
}

void pecasController::setup()
{
}

void pecasController::controllerLoop()
{
}

void pecasController::controllerTermina()
{
}

void pecasController::moveEvent(QPointF inicio, QPointF fim)
{
    qDebug()<<newGame;
    qDebug()<<int(inicio.y()/75);
    qDebug()<<int(inicio.x()/75);
    qDebug()<<int(fim.y()/75);
    qDebug()<<int(fim.x()/75);
    try{
    newGame->move/**/(2,1,3,2);//(int(inicio.y()/75),int(inicio.x()/75),int(fim.y()/75),int(fim.x()/75));
    qDebug()<<"Aqui";
    }
    catch(exception e)
    {
        qDebug()<<"Error";
    }
}
