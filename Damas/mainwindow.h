#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QLabel>
#include "jogo.h"
#include "gameview.h"
#include "pontosview.h"

class QString;
class QHBoxLayout;

class MainWindow : public QWidget,public iView
{
    Q_OBJECT
    
public:
    MainWindow(Controller *controller,QWidget *parent = 0);
    ~MainWindow();
      void iniciaLayout();
//    void iniciaScene();
//    void iniciaView();
      void inicia();
//    void iniciaPecas(int inicio, int fim, QBrush brush);
    //void updateview(Tabuleiro tab);
    //void renovaScene();

    void setController(Controller *ctr);
    Controller* getController();
    void updateView(QString changeId);

    QPointF EventPosInicial();
    QPointF EventPosFinal();

    void iniciaView();
private:
    QGraphicsScene *scene;
    gameView  *view;
    PontosView *player1;
    PontosView *player2;
    QHBoxLayout *layout;
    jogo *game;
    Controller* controller;
};

#endif // MAINWINDOW_H
