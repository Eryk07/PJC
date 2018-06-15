#include "CGMedicament.h"

CGMedicament::CGMedicament(CObject *o)
    :CGObject(o)
{
}

QPainterPath CGMedicament::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}
qreal CGMedicament::opacity(){
    CMedicament *medobject = dynamic_cast<CMedicament*>(object);
    return medobject->get_value();
}
QRectF CGMedicament::boundingRect() const
{

    return QRect(-medicament_size/2, -medicament_size/2, medicament_size, medicament_size);
}

void CGMedicament::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setBrush(Qt::darkGreen);
    painter->drawRoundedRect(boundingRect(),5,5);
}

void CGMedicament::updateG()
{
    setPos(object->get_x(), object->get_y());
    update(boundingRect());
    setOpacity(0.2 * opacity());
}
