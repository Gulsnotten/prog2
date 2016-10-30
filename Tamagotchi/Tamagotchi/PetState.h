#pragma once
#include "IState.h"
#include "Pet.h"
class PetState : public IState
{
	Pet* pet;
public:
	PetState();
	~PetState();

	bool Update(Pet* pet);
};