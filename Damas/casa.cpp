#include "casa.h"
#include <QApplication>
#include <QColor>
#include <QGraphicsItem>
#include <QSet>
#include <QPainter>

Casa::Casa()
{
}

void Casa::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawRect(QRectF(100.0,100.0,100.0,100.0));
}
