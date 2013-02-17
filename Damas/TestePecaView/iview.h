#ifndef IVIEW_H
#define IVIEW_H

#include <QString>
#include <QPointF>

class jogo;

class Controller;

class iView
{
public:
    // Items da view devem conhecer seu controle e o jogo
    virtual void setController(Controller*) = 0;
    virtual Controller* getController() = 0;

    virtual void updateView(QString changeId) = 0;

    virtual QPointF EventPosInicial() = 0;
    virtual QPointF EventPosFinal() = 0;

    iView();
};

#endif // IVIEW_H
