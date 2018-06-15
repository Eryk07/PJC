#include "CGDoctor.h"

CGDoctor::CGDoctor(CObject *o)
    :CGObject(o)
{
}

QPainterPath CGDoctor::shape() const
{
    QPainterPath path;
    path.addRect(QRect(-(man_width/2), -(man_height/2),
                       man_width, man_height));
    return path;
}

QRectF CGDoctor::boundingRect() const
{
    return QRect(-(man_width/2+5), -(man_height/2+5),
                 man_width+8, man_height+8);
}

void CGDoctor::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setBrush(Qt::white);
    painter->rotate(object->get_angle()*180/M_PI);
    painter->drawEllipse(-man_width/2, -man_height/2,
                      man_width/2, man_height);
}

void CGDoctor::updateG()
{
    setPos(object->get_x(), object->get_y());
    update(boundingRect());
}
