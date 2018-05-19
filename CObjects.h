#pragma once
#include <windows.h>
#include <string>
using namespace std;

class CObjects
{
public:
	CObjects();
	~CObjects();
	int x;
	int y;
	string name;
	//HBITMAP* bitmap;
	void Move(int step, int XSize, int YSize);

};






