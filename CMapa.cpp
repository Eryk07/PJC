#include "CMapa.h"
#include <list>

CMapa::CMapa()
{
	/*map = new CObjects*[size];
	for (int i = 0; i < size; i++)
		map[size] = new CObjects[size];

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			map[i][j].x = 0;
			map[i][j].y = 0;
			map[i][j].name = ".....";
		}
		*/
}


CMapa::~CMapa()
{
	/*for (int i = 0; i < size; i++)
		delete[]map[i];
	delete[]map;*/
	objects.clear();
}



void CMapa::addToList(CObjects* object) {
	
	objects.push_back(object);
}

//void CMapa::addToMap() {
//	int tmp = 0;
//	for (list<CObjects*>::iterator iter = objects.begin(); iter != objects.end(); iter++)
//		map[0][0] = iter;
//}

void CMapa::ShowHumans() {



}

