#include "pecasview.h"
#include <QBrush>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QGraphicsScene>

pecasView::pecasView(int i, int j,QBrush brush) : QGraphicsEllipseItem(0,0,70,70,NULL)
{
    setZValue(3);
    setBrush(brush);
    setFlags(ItemIsMovable| ItemIgnoresTransformations);
    setPos(i*75.0,j*75.0);
}

void pecasView::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseReleaseEvent(event); // move the item...
    // ...then check the bounds
    if (x() < 0)
        setPos(0, y());
    else if (x() > 525)
        setPos(525,y());

    if (y() < 0)
        setPos(x(), 0);
    else if (y() > 525)
        setPos(x(), 525);
}
