#include "PushDownAutomata.h"



PushDownAutomata::PushDownAutomata()
{
}


PushDownAutomata::~PushDownAutomata()
{
}


bool PushDownAutomata::Update() {
	if (!currentState.Update()) {
		StateSwitch();
	}
}

void PushDownAutomata::StateSwitch() {
	currentState.Exit();

	switch (currentState.getExitAction) {
	case ExitAction::change:
		ChangeState(currentState.NextState());
		break;
	case ExitAction::push:
		PushState(currentState.NextState());
		break;
	case ExitAction::revert:
		Revert();
		break;
	default:
		break;
	}

	currentState.Enter();
}

void PushDownAutomata::ChangeState(IState state) {
	currentState = state;
}
void PushDownAutomata::Revert() {
	if (history.size <= 1)
		throw std::runtime_error("PushDownAutomata::Revert()");

	history.pop_back();
	currentState = history[history.size - 1];
}
void PushDownAutomata::PushState(IState state) {
	history.push_back(state);
}