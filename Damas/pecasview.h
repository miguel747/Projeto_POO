#ifndef PECASVIEW_H
#define PECASVIEW_H

#include <QGraphicsItem>
#include <QtCore>
#include <QtGui>
#include <QPointF>

#include "iview.h"
#include "controller.h"
#include "jogo.h"

class pecasView : public QGraphicsEllipseItem, public iView
{
public:
    pecasView(int i,int j,QBrush ,Controller *ctr);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *);
    void mousePressEvent(QGraphicsSceneMouseEvent *);

    void updateView(QString changeId);
    void setController(Controller *ctr);
    Controller* getController();

    QPointF EventPosInicial();
    QPointF EventPosFinal();

private:
    QPointF         moveInicio;
    QPointF         moveFim;
    Controller      *controller;
    jogo            *game;
};

#endif // PECASVIEW_H
