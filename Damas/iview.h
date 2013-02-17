#ifndef IVIEW_H
#define IVIEW_H

#include "jogo.h"
#include "icontroller.h"

class iController;

class iView
{
public:
    // Items da view devem conhecer seu controle e o jogo
    virtual void setController(iController*) = 0;
    virtual iController* getController() = 0;
    virtual void setModel(jogo *model) = 0;
    virtual jogo* getModel() = 0;

    virtual void updateView() = 0;

    iView();
};

#endif // IVIEW_H
