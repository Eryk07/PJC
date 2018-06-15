#include "CPatient.h"
#include <QRandomGenerator>

CPatient::CPatient(CMap *m)
    :CHuman(QRandomGenerator::global()->bounded(-map_border/2, map_border/2),
              QRandomGenerator::global()->bounded(-map_border/2, map_border/2),
              QRandomGenerator::global()->bounded(0, 2*M_PI),
              50,100, m)
{
}

CPatient::~CPatient()
{
    map->deleteFromMap(this);
}

void CPatient::move()
{
    if(!(x <= map_border/2 && x >= -map_border/2 && y <= map_border/2 && y >= -map_border/2))
        {
            leave_border();
        }
        else
            move_randomly();
}


void CPatient::update()
{
    std::vector<CObject*> nearObj = map->get_nearObjList(this);

    std::vector<CDoctor*> doctors;
    std::vector<CHuman*> mans;

    std::vector<CDisease*> diseases;
    std::vector<CNonMoving*> nmobjects;

    for(unsigned int i=0; i<nearObj.size(); i++)
    {
        CHuman *man = dynamic_cast<CHuman*>(nearObj.at(i));
        if(man)
        {

            CDoctor *doc = dynamic_cast<CDoctor*>(man);
            if(doc)
                doctors.push_back(doc);

            else{
                mans.push_back(man);
                 }
        }
        else
        {
            CNonMoving *nmobj = dynamic_cast<CNonMoving*>(nearObj.at(i));
            if(nmobj){
                CDisease *dis = dynamic_cast<CDisease*>(nmobj);
                if(dis)
                {
                    qreal distance = (dis->get_x()-x)*(dis->get_x()-x)+(dis->get_y()-y)*(dis->get_y()-y);
                    distance = sqrt(distance);
                    if(distance < (man_height+man_width)/4+dis->get_value()/2)
                    diseases.push_back(dis);
                }
                else{
                    nmobjects.push_back(nmobj);
                }
            }
        }
    }

    if(diseases.size() != 0)
    {
        for(unsigned i=0; i<diseases.size(); i++)
        {
            get_infected(diseases.at(i));
        }
    }

    else if(doctors.size() !=0)
    {
        get_cure();
        get_back(nmobjects,mans);
    }

    else if(nmobjects.size() != 0)
    {
        get_back(nmobjects, mans);
    }
   // else if(mans.size()!=0)
     //   get_back(nmobjects,mans);

    else if(!(x <= map_border/2 && x >= -map_border/2 && y <= map_border/2 && y >= -map_border/2))
    {
        leave_border();
    }

    else
    {
        move();
    }
}


void CPatient::get_infected(CDisease *disease)
{
    disease->infect();
    diseases.push_back(disease);
    this->reduce_health();
}


void CPatient::reduce_health(){
    qreal totalDamage=0;

    for(unsigned int i=0; i<diseases.size(); i++)
        totalDamage+=diseases.at(i)->get_health();

    health-=totalDamage;
    if (health<10){
        health=100;     //mignie przed śmiercią

        this->die();
    }
}

void CPatient::die(){
    delete this;
}


