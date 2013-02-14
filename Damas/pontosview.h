#ifndef PLAYERPONTOSVIEW_H
#define PLAYERPONTOSVIEW_H

#include <QLabel>
#include "iview.h"
#include "jogo.h"
#include "controller.h"

class PontosView : public QLabel, public iView
{
    Q_OBJECT
public:
    explicit PontosView(QString Player,Controller *ctr,QWidget *parent = 0);

    void setController(Controller *);
    Controller* getController();
    void updateView(QString changeId);

    QPointF EventPosInicial();
    QPointF EventPosFinal();
private:
    jogo* game;
    QString player;
    Controller *controller;
    
signals:
    
public slots:
    
};

#endif // PLAYERPONTOSVIEW_H
