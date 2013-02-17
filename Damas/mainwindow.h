#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QLabel>
#include "jogo.h"
class QString;
class QHBoxLayout;

class MainWindow : public QWidget
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void iniciaLayout();
    void iniciaScene();
    void iniciaView();
    void inicia();
    void iniciaPecas(int inicio, int fim, QBrush brush);
    void updateview(Tabuleiro tab);
    void renovaScene();
private:
    QGraphicsScene *scene;
    QGraphicsView  *view;
    QLabel *player1;
    QLabel *player2;
    QHBoxLayout *layout;
    jogo *newJogo;
    void iniciaTabView(QString imCasaBranca, QString imCasaPreta);
    void iniciaPecaView();
    void iniciaLabel();
public slots:
    void moveEvent();


};

#endif // MAINWINDOW_H
