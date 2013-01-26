#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QLabel>

class MainWindow : public QWidget
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    QGraphicsScene *scene;
    QGraphicsView  *view;
    QLabel *player1;
    QLabel *player2;

};

#endif // MAINWINDOW_H
