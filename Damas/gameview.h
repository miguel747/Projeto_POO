#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <iview.h>
#include <pecasView.h>

class gameView : public QGraphicsView, public iView
{
public:
    gameView(Controller* controller);

    void setController(Controller *ctr);
    Controller* getController();
    void updateView(QString changeId);

    QPointF EventPosInicial();
    QPointF EventPosFinal();

    void updateTab(Tabuleiro *tab);
private:
    jogo* game;
    QGraphicsScene* scene;
    Controller* controller;

    QList<pecasView*> pecasBrancas;
    QList<pecasView*> pecasPretas;

    void begin(Tabuleiro* tab);
};

#endif // GAMEVIEW_H
