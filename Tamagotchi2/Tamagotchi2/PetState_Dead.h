#pragma once
#include "Printable.h"
#include "PetState.h"
class PetState_Dead : public PetState, public Printable
{
	bool Poke();
	bool revive;

	void PrintReviveMsg();
	void PrintFutilePokeMsg();
public:
	PetState_Dead();
	~PetState_Dead();

	bool Update();

	SwitchType GetSwitchType() const;
};

