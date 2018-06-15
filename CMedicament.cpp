#include "CMedicament.h"
#include <QRandomGenerator>

CMedicament::CMedicament(CMap *m)
    :CNonMoving(QRandomGenerator::global()->bounded(-map_border/2, map_border/2),
                        QRandomGenerator::global()->bounded(-map_border/2, map_border/2),
                        0,
                        0,
                        QRandomGenerator::global()->bounded(5,15),
                        QRandomGenerator::global()->bounded(1, 5),
                        m)
{
}

CMedicament::~CMedicament()
{
}

//! Zmienia jasność medykamentu
void CMedicament::update()
{
    int flash = (QRandomGenerator::global()->bounded(4));
    if(!flash)
    value = QRandomGenerator::global()->bounded(1, 5);
}

//! Usuwa lek z mapy gdy jest zebrany
void CMedicament::get_Collected()
{
    map->deleteFromMap(this);
    delete this;
}
