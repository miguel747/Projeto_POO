#ifndef PECASCONTROLLER_H
#define PECASCONTROLLER_H

#include "icontroller.h"
#include <QPointF>

class pecasController : public iController
{
public:
    pecasController();

    void setView(iView*);
    iView* getView();
    void setModel(jogo*);
    jogo* getModel();


    void inicia();
    void setup();
    void controllerLoop();
    void controllerTermina();

    void moveEvent(QPointF inicio,QPointF fim);

private:
    jogo* newGame;
    iView* view;

};

#endif // PECASCONTROLLER_H
