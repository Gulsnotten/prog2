#include "Pet_FSM.h"



Pet_FSM::Pet_FSM()
{
	_pet_ptr = new Pet();
}


Pet_FSM::~Pet_FSM()
{
	if (_pet_ptr != nullptr)
		delete _pet_ptr;
}


bool Pet_FSM::Update() {
	IState* s_ptr = &currentState;
	PetState* ps_ptr = static_cast<PetState*>(s_ptr);

	bool willSwitch = ps_ptr->Update(_pet_ptr);
	currentState = *ps_ptr;

	delete s_ptr;
	delete ps_ptr;
	/*
	this convertion feels disgusting but I don't know any other way :(
	static_cast doesn't seem to work for non-pointers
	*/

	if (willSwitch)
		StateSwitch();
}