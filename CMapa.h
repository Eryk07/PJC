#pragma once
#include <list>
#include <cstddef>
#include "CObjects.h"

class CMapa
{
public:
	CMapa();
	~CMapa();
	list<CObjects*> objects;
	void addToList(CObjects *object);
	//const int size=10;
	//CObjects** map;
	//CObjects** makeMap();
	//void addToMap();
	void ShowHumans();

};

