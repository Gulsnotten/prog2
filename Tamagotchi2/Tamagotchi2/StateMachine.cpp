#include "StateMachine.h"



StateMachine::StateMachine(PetInterface* pet_interface) : _petInterfacePtr(pet_interface), _currentStatePtr(nullptr)
{
	_petInterfacePtr->PrintStatus();
	ChangeState(new PetState_Idle());
}


StateMachine::~StateMachine()
{
}


void StateMachine::ChangeState(PetState* state) {
	_currentStatePtr = std::shared_ptr<PetState>(state);
	_currentStatePtr->Enter(_petInterfacePtr);
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