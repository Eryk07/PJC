#include "CDisease.h"
#include <QRandomGenerator>

CDisease::CDisease(CMap *m)
    :CNonMoving(QRandomGenerator::global()->bounded(-map_border/2, map_border/2),
                        QRandomGenerator::global()->bounded(-map_border/2, map_border/2),
                        0,
                        0,
                        0.1*QRandomGenerator::global()->bounded(1,5),
                        QRandomGenerator::global()->bounded(10, 50),
                        m)
{
}

CDisease::~CDisease()
{
    map->deleteFromMap(this);
}


//!Choroby rosną wraz z upływem czasu
void CDisease::update()
{
    int grow = (QRandomGenerator::global()->bounded(10));
    if(!grow)
    {
        value+=(QRandomGenerator::global()->bounded(1, 3));
        if(value>180)value=180;
    }
}


void CDisease::infect()
{
    value-=(0.5*value);
}
