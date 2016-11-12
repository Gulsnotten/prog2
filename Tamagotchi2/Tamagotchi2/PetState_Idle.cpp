#include "PetState_Idle.h"


PetState_Idle::PetState_Idle()
{
}


PetState_Idle::~PetState_Idle()
{
}

bool PetState_Idle::Update() {
	if (_petDataPtr->GetHealth() != Health::healthy) {
		return false;
	}
	
	_petDataPtr->UpdateStats();

	Interact();

	_petDataPtr->PrintStatus();

	return true;
}

void PetState_Idle::Feed() {
	_petDataPtr->Feed(_foodFactory.CreateMeal());
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