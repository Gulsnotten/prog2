#include <vector>
#include <memory>
#include "PetState.h"
#include "PetState_Idle.h"
#pragma once

class StateMachine
{
	std::vector<std::shared_ptr<PetState>> history;
	std::shared_ptr<PetData> _petDataPtr;
	std::shared_ptr<PetState> _currentStatePtr;

	void ChangeState(PetState* state);
	void PushState(PetState* state);
	void PopState();
public:
	StateMachine(std::shared_ptr<PetData> pet_data);
	~StateMachine();

	bool Update();
};

