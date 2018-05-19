#pragma once
#include "CDisease.h"
class CInfectiousDis :
	public CDisease
{
public:
	CInfectiousDis();
	~CInfectiousDis();
	int speedOfSpread;
};

