#pragma once
#include "PetState.h"
class PetState_Dead : public PetState
{
	bool Poke();
	bool revive;
public:
	PetState_Dead();
	~PetState_Dead();

	bool Update();

	SwitchType GetSwitchType() const;
};

