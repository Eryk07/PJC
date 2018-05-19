#include "CObjects.h"



CObjects::CObjects()
{
	x = 50;
	y = 50;
	name = "bum";
}


CObjects::~CObjects()
{
	//DeleteObject(bitmap);
}

void CObjects::Move(int step, int XSize, int YSize) {

	this->x = this->x + step;
	this->y = this->y + step;

	if (this->x >= XSize - 50) // put the -50 else it'll let you to up to x point
	{
		this->x = XSize - 50;
		step = -step++;// put ++ so its less predictable
	}

	if (this->y >= YSize - 50)
	{
		this->y = YSize - 50;
		step = -step++;
	}

	if (this->x < 50)
	{
		this->x = 50;
		step = -step;
	}

	if (this->y < 50)
	{
		this->y = 50;
		step = -step;
	}
}

