#ifndef PECASVIEW_H
#define PECASVIEW_H

#include <QGraphicsItem>

class pecasView : public QGraphicsEllipseItem
{
public:
    pecasView(int i,int j,QBrush );
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *);
};

#endif // PECASVIEW_H
