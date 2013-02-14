#include "controller.h"
#include <QDebug>

void Controller::addView(iView *view)
{
    views.append(view);
}

void Controller::notifyEvent(QString eventId, iView *sender)
{
    if(eventId == "MOVED")
    {
        QPointF iPos = sender->EventPosInicial();
        QPointF fPos = sender->EventPosFinal();
        try
        {
            qDebug()<<int(iPos.x()/75);
            qDebug()<<int(iPos.y()/75);
            qDebug()<<int(fPos.x()/75);
            qDebug()<<int(fPos.y()/75);
            game->move(int(iPos.y()/75),int(iPos.x()/75),int(fPos.y()/75),int(fPos.x()/75));
            qDebug()<<"movimento feito";
        }
        catch(exception)
        {
            qDebug()<<"Exceçao";
            game->notify("BadMove");
        }
    }
}

Controller::Controller()
{
    game = jogo::getInstance();
}

void Controller::star()
{
    game->newGame();
}
