#include "CHumans.h"



CHumans::CHumans()
{
	health = 100;
}


CHumans::~CHumans()
{
}

void CHumans::getInfected(CDisease disease)
{
		
	if (x == disease.x && y == disease.y)
		diseases.push_back(disease);
}

