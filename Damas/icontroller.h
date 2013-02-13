#ifndef ICONTROLLER_H
#define ICONTROLLER_H

#include "jogo.h"
#include "iview.h"
class iView;

class iController
{
public:
    virtual void setView(iView*) = 0;
    virtual iView* getView() = 0;
    virtual void setModel(jogo*) = 0;
    virtual jogo* getModel() = 0;

    iController();

    virtual void inicia() = 0;
    virtual void setup() = 0;
    virtual void controllerLoop() = 0;
    virtual void controllerTermina() = 0;
};

#endif // ICONTROLLER_H
