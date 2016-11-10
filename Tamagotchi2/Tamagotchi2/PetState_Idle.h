#pragma once
#include "PetState.h"
class PetState_Idle : public PetState
{
	void Feed();
	void Wash();
	void Play();
public:
	PetState_Idle();
	~PetState_Idle();

	bool Update();
};

