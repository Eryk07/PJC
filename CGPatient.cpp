#include "CGPatient.h"

CGPatient::CGPatient(CObject *o)
    :CGObject(o)
{
}

QPainterPath CGPatient::shape() const
{
    QPainterPath path;
    path.addRect(QRect(-(man_width/2), -(man_height/2), man_width, man_height));
    return path;
}

QRectF CGPatient::boundingRect() const
{
    return QRect(-(man_width/2+5), -(man_height/2+5), man_width+10, man_height+10);
}

void CGPatient::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setBrush(Qt::yellow);
    painter->rotate(object->get_angle()*180/M_PI);
    painter->drawRect(-man_width/2, -man_height/2, man_width, man_height);
}

void CGPatient::updateG()
{
    setPos(object->get_x(), object->get_y());
    setOpacity(0.01* (object->get_health()) );
    update(boundingRect());
}
