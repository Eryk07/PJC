#include "CGObject.h"

CGObject::CGObject(CObject *o)
{
    object=o;
    map=o->get_map();
    setPos(o->get_x(), o->get_y());
}

CObject* CGObject::get_CObject()
{
    return object;
}

