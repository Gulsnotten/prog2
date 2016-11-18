#pragma once
#include "PetState.h"
#include "Printable.h"
class PetState_Sleep : public PetState
{
public:
	PetState_Sleep();
	~PetState_Sleep();

	bool Update();
};

