#include "CDoctor.h"
#include <QRandomGenerator>

CDoctor::CDoctor(CMap *m)
    :CHuman(QRandomGenerator::global()->bounded(-map_border/2, map_border/2),
              QRandomGenerator::global()->bounded(-map_border/2, map_border/2),
              QRandomGenerator::global()->bounded(0, 2*M_PI),
              50,100, m)
{
}

CDoctor::~CDoctor()
{
    map->deleteFromMap(this);
}


void CDoctor::move()
{
    std::vector<CObject*> nearObj = map->get_nearObjList(this);
    std::vector<CMedicament*> medicaments;
    std::vector<CPatient*> patients;

    for(unsigned int i=0; i<nearObj.size(); i++)
    {
        CMedicament *med = dynamic_cast<CMedicament*>(nearObj.at(i));
        if(med)
        {
            medicaments.push_back(med);
        }
        CPatient *pat = dynamic_cast<CPatient*>(nearObj.at(i));
        if (pat){
            patients.push_back(pat);
        }

    }

    if(medicaments.size() != 0)
    {
        unsigned int nearliest = 0;
        qreal nearliestDistance = range;
        for(unsigned int i=0; i<medicaments.size(); i++)
        {
            qreal distance = (medicaments.at(i)->get_x()-x)*(medicaments.at(i)->get_x()-x)+(medicaments.at(i)->get_y()-y)*(medicaments.at(i)->get_y()-y);
            if(distance < nearliestDistance)
            {
                nearliest = i;
                nearliestDistance = distance;
            }
        }
        go_to(medicaments.at(nearliest));


    }
   else if(patients.size() != 0)
    {
        unsigned int nearliest = 0;
        qreal nearliestDistance = range;
        for(unsigned int i=0; i<patients.size(); i++)
        {
            qreal distance = (patients.at(i)->get_x()-x)*(patients.at(i)->get_x()-x)+(patients.at(i)->get_y()-y)*(patients.at(i)->get_y()-y);
            if(distance < nearliestDistance)
            {
                nearliest = i;
                nearliestDistance = distance;
            }
        }
        go_to(patients.at(nearliest));
    }
    else if(!(x <= map_border/2 && x >= -map_border/2 && y <= map_border/2 && y >= -map_border/2))
    {
        leave_border();
    }
    else
        move_randomly();
}

void CDoctor::update()
{


    std::vector<CObject*> nearObj = map->get_nearObjList(this);

    std::vector<CPatient*> patients;
    std::vector<CHuman*> mans;

    std::vector<CMedicament*> medicaments;
    std::vector<CNonMoving*> nmobjects;
    for(unsigned int i=0; i<nearObj.size(); i++)
    {
        CHuman *man = dynamic_cast<CHuman*>(nearObj.at(i));
        if(man)
        {
            CPatient *pat = dynamic_cast<CPatient*>(man);
            if(pat)
                patients.push_back(pat);

            else{
                mans.push_back(man);
                 }
        }
        else
        {
            CNonMoving *nmobj = dynamic_cast<CNonMoving*>(nearObj.at(i));
            if(nmobj){
                CMedicament *med = dynamic_cast<CMedicament*>(nmobj);
                if(med)
                {
                    qreal distance = (med->get_x()-x)*(med->get_x()-x)+(med->get_y()-y)*(med->get_y()-y);
                    distance = sqrt(0.8*distance);
                    if(distance < (man_height+man_width)/4+med->get_value()/2)
                    medicaments.push_back(med);
                }
                else{
                    nmobjects.push_back(nmobj);
                }
            }
        }
    }

    if(medicaments.size() != 0)
    {
        for(unsigned i=0; i<medicaments.size(); i++)
        {
            collect(medicaments.at(i));
        }
    }
    else if(patients.size() !=0)
    {
        for(unsigned i=0; i<patients.size(); i++)
        {
        cure(patients.at(i));
        }
        get_back(nmobjects,mans);
    }
    else if(nmobjects.size()!=0)
        get_back(nmobjects, mans);
 //   else if(mans.size()!=0)
    //    get_back(nmobjects,mans);

    else if(!(x <= map_border/2 && x >= -map_border/2 && y <= map_border/2 && y >= -map_border/2))
    {
        leave_border();
    }

    else
        move();
}

void CDoctor::collect(CMedicament *medicament)
{
    medicaments.push_back(medicament);
    medicament->get_Collected();
}

void CDoctor::cure(CHuman *man){
    man->get_cure();
}
