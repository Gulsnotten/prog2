#include "PetState_Idle.h"


PetState_Idle::PetState_Idle()
{
}


PetState_Idle::~PetState_Idle()
{
}

bool PetState_Idle::Update() {
	_petDataPtr->UpdateStats();

	Interact();

	_petDataPtr->PrintStatus();

	if (_petDataPtr->GetHealth() == Health::healthy) {
		return true;
	}
	else
		return false;
}

void PetState_Idle::Feed() {
	_petDataPtr->Feed();

	std::cout << _petDataPtr->GetName() << " munched on the food.\n";
}

void PetState_Idle::Wash() {
	PetState_Default::Wash();
}

void PetState_Idle::Play() {
	_petDataPtr->Play();
}

PetState* PetState_Idle::NextState() const{
	if (_petDataPtr->GetHealth() == Health::sick) {
		return new PetState_Sick();
	}
	else{
		return new PetState_Dead();
	}
}

SwitchType PetState_Idle::GetSwitchType() const {
	return SwitchType::push;
}