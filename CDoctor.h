#pragma once
#include "CHumans.h"
#include "CMedicament.h"
class CDoctor :
	public CHumans
{
public:
	CDoctor();
	~CDoctor();
	void cure();
	CMedicament* drugs;
	};

