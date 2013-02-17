#ifndef ICONTROLLER_H
#define ICONTROLLER_H


class iView;

#include "jogo.h"

class Controller
{
public:
    void addView(iView* view);
    void notifyEvent(QString eventId,iView *sender);
    Controller();
    void star();
private:
    QList<iView*> views;
    jogo *game;
};

#endif // ICONTROLLER_H
