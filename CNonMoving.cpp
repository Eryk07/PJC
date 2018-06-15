#include "CNonMoving.h"

CNonMoving::CNonMoving(qreal xv, qreal yv, qreal anglev, qreal rangev,qreal healthv, qreal valuev, CMap *m)
    :CObject(xv, yv, anglev, rangev,healthv, m)
{
    value=valuev;
}

qreal CNonMoving::get_value()
{
    return value;
}
