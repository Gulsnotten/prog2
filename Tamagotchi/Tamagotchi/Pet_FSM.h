#pragma once
#include "PushDownAutomata.h"
#include "PetState.h"
class Pet_FSM : public PushDownAutomata
{
	Pet* _pet_ptr;
public:
	Pet_FSM();
	~Pet_FSM();

	bool Update();
};

