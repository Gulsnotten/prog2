#include "StateMachine.h"



StateMachine::StateMachine(std::shared_ptr<PetData> pet_data) : _petDataPtr(pet_data), _currentStatePtr(nullptr)
{
	_petDataPtr->PrintStatus();
	ChangeState(new PetState_Idle());
}


StateMachine::~StateMachine()
{
}


void StateMachine::ChangeState(PetState* state) {
	_currentStatePtr = std::shared_ptr<PetState>(state);
	_currentStatePtr->Enter(_petDataPtr);
}

void StateMachine::PushState(PetState* state) {
	history.push_back(_currentStatePtr);
	ChangeState(state);
}

void StateMachine::PopState() {
	_currentStatePtr = history[history.size() - 1];
	history.pop_back();
}

bool StateMachine::Update() {
	bool ret = _currentStatePtr->Update();

	if (!ret) {
		_currentStatePtr->Exit();

		switch (_currentStatePtr->GetSwitchType()) {
		case SwitchType::switch_:
			ChangeState(_currentStatePtr->NextState());
			break;
		case SwitchType::push:
			PushState(_currentStatePtr->NextState());
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