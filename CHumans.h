#pragma once
#include "CObjects.h"
#include "CDisease.h"
#include <list>
class CHumans :
	public CObjects
{
public:
	CHumans();
	~CHumans();
	int health;
	int predispostion;
	list<CDisease> diseases;
	void getInfected(CDisease disease);

};

