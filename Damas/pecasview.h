#ifndef PECASVIEW_H
#define PECASVIEW_H

#include <QGraphicsItem>
#include <QtCore>
#include <QtGui>
#include <QPointF>

#include "iview.h"


class pecasView : public QGraphicsEllipseItem, public iView
{
public:
    pecasView(int i,int j,QBrush );
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *);
    void mousePressEvent(QGraphicsSceneMouseEvent *);

    void updateView();
    void setController(iController *);
    iController* getController();
    void setModel(jogo *model);
    jogo* getModel();
private:
    QPointF moveInicio;
    QPointF moveFim;
    iController *controller;
    jogo* newGame;
};

#endif // PECASVIEW_H
