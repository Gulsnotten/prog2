#include "Pet_PDA.h"



Pet_PDA::Pet_PDA()
{
}


Pet_PDA::~Pet_PDA()
{
}


void Pet_PDA::SwitchState(PetState* state) {
	std::unique_ptr<PetState> tmp(state); //wrap it then trash it
	current_state = *tmp.get();
	current_state.Enter(pet_data);
}

void Pet_PDA::PushState(PetState* state) {
	history.push_back(current_state);
	SwitchState(state);
}

void Pet_PDA::PopState() {
	current_state = history[history.size() - 1];
	history.pop_back();
}

bool Pet_PDA::Update() {
	bool ret = current_state.Update();

	if (!ret) {
		current_state.Exit();

		switch (current_state.GetSwitchType()) {
		case SwitchType::switch_:
			SwitchState(current_state.NextState());
			break;
		case SwitchType::push:
			PushState(current_state.NextState());
			break;
		case SwitchType::pop:
			PopState();
			break;
		default:
			break;
		}
	}

	return true;
}