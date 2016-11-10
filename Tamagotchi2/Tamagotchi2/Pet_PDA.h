#include <vector>
#include <memory>
#include "PetState.h"
#pragma once

class Pet_PDA
{
	std::vector<PetState> history;
	std::shared_ptr<PetData> pet_data = nullptr;
	PetState current_state;

	void SwitchState(PetState* state);
	void PushState(PetState* state);
	void PopState();
public:
	Pet_PDA();
	~Pet_PDA();

	bool Update();
};

