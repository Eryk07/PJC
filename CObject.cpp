#include "CObject.h"

CObject::CObject(qreal xv, qreal yv, qreal anglev, qreal rangev,qreal healthv, CMap *m)
{
    x=xv;
    y=yv;
    angle=anglev;
    range=rangev;
    health=healthv;
    map = m;
}

qreal CObject::get_x()
{
    return x;
}

qreal CObject::get_y()
{
    return  y;
}

qreal CObject::get_angle()
{
    return angle;
}

qreal CObject::get_range()
{
    return range;
}

qreal CObject::get_health()
{
    return  health;
}

CMap *CObject::get_map()
{
    return map;
}
