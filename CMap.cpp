#include "CMap.h"
#include <QApplication>
#include <QGraphicsView>
#include <QRandomGenerator>
#include "math.h"
#include "CPatient.h"
#include "CGPatient.h"
#include "CDoctor.h"
#include "CGDoctor.h"
#include "CDisease.h"
#include "CGDisease.h"
#include "CMedicament.h"
#include "CGMedicament.h"

using namespace std;

CMap::CMap(QGraphicsScene *s)
{
    scene = s;
    qreal disAmount = 8;

    for(int i=0; i<disAmount; i++)
    {
        CDisease *dis = new CDisease(this);
        addObject(dis);
        CGDisease *gdis = new CGDisease(dis);
        addGObject(gdis);
        scene->addItem(gdis);
    }

    qreal patAmount = 5;

    for(int i=0; i<patAmount; i++)
    {
        CPatient *pat = new CPatient(this);
        addObject(pat);
        CGPatient *gpat = new CGPatient(pat);
        addGObject(gpat);
        scene->addItem(gpat);
    }

    qreal docAmount = 3;

    for(int i=0; i< docAmount; i++)
    {
        CDoctor *doc = new CDoctor(this);
        addObject(doc);
        CGDoctor *gdoc = new CGDoctor(doc);
        addGObject(gdoc);
        scene->addItem(gdoc);
    }


    qreal medAmount = 5;
    for(int i=0; i<medAmount; i++)
    {
        CMedicament *med = new CMedicament(this);
        addObject(med);
        CGMedicament *gmed = new CGMedicament(med);
        addGObject(gmed);
        scene->addItem(gmed);
    }

}

vector<CObject*> CMap::get_nearObjList(CObject *o)
{
    vector<CObject*> nearObj;

    for(unsigned int i=0; i<ObjectList.size(); i++){
        qreal distance = ((ObjectList.at(i)->get_x()-o->get_x())*(ObjectList.at(i)->get_x()-o->get_x()))+((ObjectList.at(i)->get_y()-o->get_y())*(ObjectList.at(i)->get_y()-o->get_y()));
        distance = sqrt(distance);

        if(distance <= o->get_range())
            if(o != ObjectList.at(i))
                nearObj.push_back(ObjectList.at(i));

        distance = 0;
    }

    return nearObj;
}

void CMap::addObject(CObject *object)
{
    ObjectList.push_back(object);
}

void CMap::addGObject(CGObject *gobject)
{
    GObjectList.push_back(gobject);
}

void CMap::deleteFromMap(CObject *o)
{
    unsigned int size=GObjectList.size();
    for(unsigned int i=0; i<size; i++){
        CGObject *gobject = GObjectList.at(i);
        if(gobject->get_CObject() == o)
        {
            gobject->scene()->removeItem(gobject);
            GObjectList.erase(GObjectList.begin()+i);
            delete gobject;
            break;
        }
    }
    size=ObjectList.size();
    for(unsigned int i=0; i<size; i++)
    {
        CObject *object = ObjectList.at(i);
        if(object == o)
        {
            ObjectList.erase(ObjectList.begin()+i);
            break;
        }
    }
}
