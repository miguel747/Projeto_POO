#ifndef CASA_H
#define CASA_H

#include <QApplication>
#include <QColor>
#include <QGraphicsItem>
#include <QSet>

class Casa : QGraphicsItem
{
public:
    Casa();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // CASA_H
