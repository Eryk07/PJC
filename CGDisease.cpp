#include "CGDisease.h"

CGDisease::CGDisease(CObject *o)
    :CGObject(o)
{
}

QPainterPath CGDisease::shape() const
{
    QPainterPath path;
    path.addEllipse(boundingRect());
    return path;
}

QRectF CGDisease::boundingRect() const
{
    CNonMoving *nmobject = dynamic_cast<CNonMoving*>(object);
    int size = nmobject->get_value();
    return QRect(-size/2, -size/2, size, size);
}

void CGDisease::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setBrush(Qt::red);
    painter->setOpacity(0.4);
    painter->drawEllipse(boundingRect());
}

void CGDisease::updateG()
{
    setPos(object->get_x(), object->get_y());
    update(boundingRect());
}
