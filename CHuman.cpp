#include "CHuman.h"
#include "cmath"
#include <QRandomGenerator>

CHuman::CHuman(qreal xv, qreal yv, qreal anglev, qreal rangev,qreal healthv, CMap *m)
   :CObject(xv,yv,anglev,rangev,healthv,m)
{
}



void CHuman::move_randomly()
{
    if(!((QRandomGenerator::global()->bounded(8))))
    {
        qreal tempo = 0.05*M_PI;
        if( (QRandomGenerator::global()->bounded(1)) )
            angle = angle + tempo;
        else
            angle = angle - tempo;
    }
    x = x + man_speed*cos(angle);
    y = y + man_speed*sin(angle);
}

void CHuman::leave_border()
{
    qreal tempo = 0.1*M_PI * QRandomGenerator::global()->bounded(0, 3);

    qreal dminus = 0;
    qreal dplus = 0;

    qreal x_tmp = x + cos(angle + tempo) * man_speed;
    qreal y_tmp = y + sin(angle + tempo) * man_speed;

            if(x <= -map_border/2)
            {
                dminus += abs(-map_border/2 - x_tmp);
            }
            else if(x >= map_border/2)
            {
                dminus += abs(map_border/2 - x_tmp);
            }
            else if(y <= -map_border/2)
            {
                dminus += abs(-map_border/2 - y_tmp);
            }
            else if(y >= map_border/2)
            {
                dminus += abs(map_border/2 - y_tmp);
            }
      x_tmp = x + cos(angle + tempo) * man_speed;
      y_tmp = y + sin(angle + tempo) * man_speed;

            if(x <= -map_border/2)
            {
                dplus += abs(-map_border/2 - x_tmp);
            }
            else if(x >= map_border/2)
            {
                dplus += abs(map_border/2 - x_tmp);
            }
            else if(y <= -map_border/2)
            {
                dplus += abs(-map_border/2 - y_tmp);
            }
            else if(y >= map_border/2)
            {
                dplus += abs(map_border/2 - y_tmp);
            }
    if(dplus <= dminus)
        angle += tempo;
    else
        angle -= tempo;

    x += cos(angle) * man_speed;
    y += sin(angle) * man_speed;
}


void CHuman::go_to(CObject *o)
{
    qreal tempo = M_PI/9;

    x += man_speed*cos(angle);
    y += man_speed*sin(angle);

    qreal x1 = cos(angle);
    qreal y1 = sin(angle);
    qreal x2 = (o->get_x()-x);
    qreal y2 = (o->get_y()-y);
    qreal dot = x1*x2 + y1*y2;
    qreal det = x1*y2 - y1*x2;

    qreal diff = atan2(det, dot);
    if(abs(diff) > diff/2 && abs(diff) <= M_PI)
    {
        if(diff > 0)
            angle = angle + tempo;
        else
            angle = angle -  tempo;
    }
    if(abs(diff) > diff/2 && abs(diff) > M_PI)
    {
        if(diff < 0)
            angle = angle + tempo;
        else
            angle = angle + tempo;
    }
}
void CHuman::get_back(std::vector<CNonMoving*> o, std::vector<CHuman*> man)
{
    qreal diff = M_PI/9;

    qreal x_test = x + man_speed * cos(angle);
    qreal y_test = y + man_speed * sin(angle);
    bool crash = 0;
    bool will_crash = 1;

    for(unsigned int i = 0; i<o.size(); i++)
    {
        qreal distance = (o[i]->get_x()-x_test)*(o[i]->get_x()-x_test)+(o[i]->get_y()-y_test)*(o[i]->get_y()-y_test);
        distance = sqrt(distance);
        if(distance < ((1.5*man_height+man_width)/2+o[i]->get_value()/2))
            will_crash = 1;
    }
    for(unsigned int i = 0; i<o.size(); i++)
    {
        qreal distance = (o[i]->get_x()-x)*(o[i]->get_x()-x)+(o[i]->get_y()-y)*(o[i]->get_y()-y);
        distance = sqrt(distance);
        if(distance < ((1.5*man_height+man_width)/3+o[i]->get_value()/2))
            will_crash = 1;
    }
    for(unsigned int i = 0; i<man.size(); i++)
    {
        qreal distance = (man[i]->get_x()-x)*(man[i]->get_x()-x)+(man[i]->get_y()-y)*(man[i]->get_y()-y);
        distance = sqrt(distance);
        if(distance < 1.5*(man_height+man_width))
            crash = 1;
    }
    for(unsigned int i = 0; i<man.size(); i++)
    {
        qreal distance = (man[i]->get_x()+man_speed*cos(man[i]->get_angle())-x_test)
                *(man[i]->get_x()+man_speed*cos(man[i]->get_angle())-x_test)
                +(man[i]->get_y()+man_speed*sin(man[i]->get_angle())-y_test)
                *(man[i]->get_y()+man_speed*sin(man[i]->get_angle())-y_test);
        distance = sqrt(distance);
        if(distance < 1.5*(man_height+man_width))
            will_crash = 1;
    }

    if(!crash || (crash && !will_crash && man.size()+o.size() > 3))
    {
        x += man_speed * cos(angle);
        y += man_speed * sin(angle);
    }

    else
    {
        qreal dist_plus = 0;
        qreal dist_minus = 0;

        qreal x_test = x + cos(angle + diff) * man_speed;
        qreal y_test = y + sin(angle + diff) * man_speed;
        for(unsigned int i = 0; i<o.size(); i++)
        {
            qreal distance = (o[i]->get_x()-x_test)*(o[i]->get_x()-x_test)+(o[i]->get_y()-y_test)*(o[i]->get_y()-y_test);
            distance = sqrt(distance);
            dist_plus += distance;
        }
        for(unsigned int i = 0; i<man.size(); i++)
        {
            qreal distance = (man[i]->get_x()-x_test)*(man[i]->get_x()-x_test)+(man[i]->get_y()-y_test)*(man[i]->get_y()-y_test);
            distance = sqrt(distance);
            dist_plus += distance;
        }

        x_test = x + cos(angle - diff) * man_speed;
        y_test = y + sin(angle - diff) * man_speed;
        for(unsigned int i = 0; i<o.size(); i++)
        {
            qreal distance = (o[i]->get_x()-x_test)*(o[i]->get_x()-x_test)+(o[i]->get_y()-y_test)*(o[i]->get_y()-y_test);
            distance = sqrt(distance);
            dist_minus += distance;
        }
        for(unsigned int i = 0; i<man.size(); i++)
        {
            qreal distance = (man[i]->get_x()-x_test)*(man[i]->get_x()-x_test)+(man[i]->get_y()-y_test)*(man[i]->get_y()-y_test);
            distance = sqrt(distance);
            dist_minus += distance;
        }

        if(dist_plus >= dist_minus)
            angle += diff;
        else
            angle -= diff;
    }
}

void CHuman::get_cure(){
    health=100;
}
