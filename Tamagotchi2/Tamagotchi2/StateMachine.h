#include <vector>
#include <memory>
#include "PetState.h"
#include "PetState_Idle.h"
#include "Observer.h"
#include "PetState_Sleep.h"
#include "DayNightCycle.h"
#pragma once

class StateMachine : public Observer
{
	std::vector<std::shared_ptr<PetState>> history;
	std::shared_ptr<PetInterface> _petInterfacePtr;
	std::shared_ptr<PetState> _currentStatePtr;
	std::shared_ptr<PetState_Sleep> _sleepStatePtr;

	std::weak_ptr<PetState> _switchPtr;

	void ChangeState(PetState* state);
	void PushState(PetState* state);
	void PopState();
public:
	StateMachine(PetInterface* pet_interface);
	~StateMachine();

	bool Update();
	void Notify(Subject* subject);
};

