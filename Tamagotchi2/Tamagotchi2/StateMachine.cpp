#include "StateMachine.h"



StateMachine::StateMachine(std::shared_ptr<PetData> pet_data)
{
	_petDataPtr = pet_data;
	_petDataPtr->PrintStatus();
	ChangeState(new PetState_Idle());
}


StateMachine::~StateMachine()
{
}


void StateMachine::ChangeState(PetState* state) {
	current_state = std::shared_ptr<PetState>(state);
	current_state->Enter(_petDataPtr);
}

void StateMachine::PushState(PetState* state) {
	history.push_back(current_state);
	ChangeState(state);
}

void StateMachine::PopState() {
	current_state = history[history.size() - 1];
	history.pop_back();
}

bool StateMachine::Update() {
	bool ret = current_state->Update();

	if (!ret) {
		current_state->Exit();

		switch (current_state->GetSwitchType()) {
		case SwitchType::switch_:
			ChangeState(current_state->NextState());
			break;
		case SwitchType::push:
			PushState(current_state->NextState());
			break;
		case SwitchType::pop:
			PopState();
			break;
		case SwitchType::kill:
			return false;
		default:
			break;
		}
	}

	return true;
}